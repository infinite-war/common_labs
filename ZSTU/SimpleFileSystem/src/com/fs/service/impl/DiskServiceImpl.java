package com.fs.service.impl;

import com.fs.constant.Constants;
import com.fs.pojo.*;
import com.fs.service.DirService;
import com.fs.service.DiskService;
import com.fs.utils.Utility;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

/**
 * @author 陈伟剑
 * @desc 磁盘操作实现类
 * @date 2022/12/3 15:14
 */
public class DiskServiceImpl implements DiskService {
    private static final DirService dirService = new DirServiceImpl();

    /**dfs删除目录**/
    public void dfsDelete(FCB fcb){
        if(fcb.getChildren().isEmpty()){
            freeFile(fcb);
        }

        for(FCB child : fcb.getChildren()){
            dfsDelete(child);
        }
    }

    /**释放目录中所有文件占用内存（借助栈）**/
    @Override
    public Boolean freeDir(FCB fcb) {
        dfsDelete(fcb);
        return null;
    }

    /**清除文件占据的磁盘空间及改变FAT表**/
    @Override
    public Boolean freeFile(FCB fcb) {
        FAT[] fats = Memory.getINSTANCE().getFat();
        FAT temp_1 = fats[fcb.getIndexNode().getFirstBlock()];
        FAT temp_2 = null;
        int curEmptyNum=Memory.getINSTANCE().getEmptyBlockNum();
        //1.修改FAT表 双指针改法
        while(temp_1.getNextId() != -1){
            temp_2 = temp_1;
            temp_1 = fats[temp_1.getNextId()];
            //断开前后连接
            temp_2.setNextId(-1);
            //将占据的盘块对应内容置空 （这里是假置空 考虑到直接将磁盘块置空消耗内存不实际）
            temp_2.setBitmap(0);
            curEmptyNum++;
        }
        temp_1.setBitmap(0);
        curEmptyNum++;
        Memory.getINSTANCE().setEmptyBlockNum(curEmptyNum);
        //3.递归修改父目录文件大小
        dirService.updateSize(fcb,false,-1);
        //4.索引结点大小变为0 空文件
        fcb.getIndexNode().setSize(0);
        return true;
    }

    /**将内容写入磁盘块**/
    @Override
    public int writeToDisk(String content) {
        //判断是否有足够的磁盘空间
        int needNum = Utility.ceilDivide(content.length(), Constants.BLOCK_SIZE);
        if(needNum > Memory.getINSTANCE().getEmptyBlockNum()){
            System.out.println("[error]: 磁盘空间不足！");
            return -1;
        }
        //开始写入 双指针写入法
        FAT[] fats = Memory.getINSTANCE().getFat();
        int first = -1;
        //找到第一个
        first = findEmpty();
        int temp_1 = first;
        int temp_2 = -1;
        Block[] disk = Disk.getINSTANCE().getDisk();
        int i = 0;
        for (; i < needNum - 1; i++) {
            //拆分存储输入的字符
            String splitString = content.substring(i*Constants.BLOCK_SIZE,(i+1)*Constants.BLOCK_SIZE);
            //存储到磁盘
            disk[temp_1].setContent(splitString);
            fats[temp_1].setBitmap(1);
            temp_2 = temp_1;
            //寻找下一个空闲块
            temp_1 = findEmpty();
            fats[temp_2].setNextId(temp_1);
        }
        //设置最后一个块
        disk[temp_1].setContent(content.substring((i)*Constants.BLOCK_SIZE));
        fats[temp_1].setNextId(-1);
        fats[temp_1].setBitmap(1);
        //返回第一个磁盘块号
        return first;
    }

    /**寻找空闲块,和linux一样，这里通过位图来标记什么块处于空闲状态**/
    @Override
    public int findEmpty() {
        FAT[] fats = Memory.getINSTANCE().getFat();
        for (int i = 0; i < fats.length; i++) {
            if(fats[i].getBitmap() == 0){
                return i;
            }
        }
        return -1;
    }
}
