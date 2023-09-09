package com.fs.service.impl;

import com.fs.constant.Constants;
import com.fs.constant.FontColor;
import com.fs.pojo.*;
import com.fs.service.DirService;
import com.fs.service.FileService;
import com.fs.utils.Utility;
import com.fs.view.View;

import java.util.Date;
import java.util.LinkedList;
import java.util.List;
import java.util.Objects;

/**
 * @author 陈伟剑
 * @desc 目录操作实现类
 * @date 2022/12/3 15:13
 */
public class DirServiceImpl implements DirService {
    private static final DirService dirService = new DirServiceImpl();

    /**显示当前目录下的所有文件项
     * 白色 普通文件
     * 绿色 可执行文件
     * 红色 压缩文件
     * 蓝色 目录文件
     * **/
    @Override
    public void ll() {
        Memory memory = Memory.getINSTANCE();
        List<FCB> children = memory.getCurDir().getChildren();
        System.out.println("目录权限\t  文件项数  创建者  文件大小\t\t 修改时间\t\t\t\t\t文件名");
        for (int i = 0; i < children.size(); i++) {
            FCB fcb = children.get(i);
            if(fcb.getType().equals(Constants.C_FILE)){
                if(Utility.getSuffix(fcb.getFileName()).matches("exe")){
                    //绿色
                    View.showFcb(fcb, FontColor.GREEN);
                }else if(Utility.getSuffix(fcb.getFileName()).matches("(tar|zip|7z|rar)")){
                    //红色
                    View.showFcb(fcb,FontColor.RED);
                }else {
                    //普通文件
                    View.showFcb(fcb,FontColor.WHITE);
                }
            }else { // 目录
                //蓝色
                View.showFcb(fcb,FontColor.BLUE);
            }
        }
    }

    /**显示当前目录下的所有文件文件名**/
    @Override
    public void ls() {
        Memory memory = Memory.getINSTANCE();
        List<FCB> children = memory.getCurDir().getChildren();
        for (FCB fcb : children) {
            if (fcb.getType().equals('N')) {
                if (Utility.getSuffix(fcb.getFileName()).equals("exe")) {
                    System.out.print(Utility.getFormatLogString(fcb.getFileName(), FontColor.GREEN, 0) + " ");
                } else if (Utility.getSuffix(fcb.getFileName()).matches("(tar|zip|7z|rar)")) {
                    System.out.print(Utility.getFormatLogString(fcb.getFileName(), FontColor.RED, 0) + " ");
                } else {
                    System.out.print(fcb.getFileName() + " ");
                }
            } else {
                System.out.print(Utility.getFormatLogString(fcb.getFileName(), FontColor.BLUE, 0) + " ");
            }
        }
    }

    /**创建目录**/
    @Override
    public Boolean mkdir(String dirName,String permission) {
        FCB curDir = Memory.getINSTANCE().getCurDir();
        User user = Memory.getINSTANCE().getCurUser();
        List<FCB> children = curDir.getChildren();

        if(!Utility.isRightDirName(dirName,children)){
            return false;
        }

        //创建索引节点 创建FCB 文件大小为0 空文件
        IndexNode indexNode = new IndexNode(permission, 0, -1, 0, user.getUserName(), new Date());
        FCB fcb = new FCB(dirName, Constants.D_FILE, indexNode, curDir, new LinkedList<>());
        //将文件控制块放入磁盘的fcb集合
        Disk.getINSTANCE().getFcbList().add(fcb);
        //修改父目录的文件项 加入父目录儿子集合
        curDir.getIndexNode().addFcbNum();
        curDir.getChildren().add(fcb);
        System.out.println("[success]: 创建目录成功");
        return true;
    }

    /**切换目录**/
    @Override
    public Boolean cd(String path) {

        //解析路径
        FCB fcb = dirService.pathResolve(path);
        //null 不存在
        if(fcb.getType()== Constants.U_FILE){
            System.out.println("[error]: 目标目录不存在");
            return false;
        }else if(fcb.getType().equals(Constants.C_FILE)){
            //type N 不是目录文件
            System.out.println("[error]: 无法进入普通文件");
            return false;
        }else {
            //type D 切换到对应目录
            //判断权限
            int permission = Utility.checkPermission(fcb);
            if(permission == 0){
                System.out.println("[error]: 无权限");
                return false;
            }
            Memory.getINSTANCE().setCurDir(fcb);
        }
        return null;
    }

    /**解析路径**/
    @Override
    public FCB pathResolve(String path) {
        path = path.trim();
        FCB curDir = Memory.getINSTANCE().getCurDir();
        FCB rootDir = Memory.getINSTANCE().getRootDir();

        //判断是否直接切换到根目录
        if("/".equals(path)){
            Memory.getINSTANCE().setCurDir(Memory.getINSTANCE().getRootDir());
            return rootDir;
        }
        //判断是不是. ./
        if(".".equals(path) || "./".equals(path)){
            return curDir;
        }
        //判断是不是..  ../
        if("..".equals(path) || "../".equals(path)){
            //根目录无法再往父节点走了
            if(curDir != Memory.getINSTANCE().getRootDir()){
                //返回当前目录的父目录
                return curDir.getFather();
            }
            return rootDir;
        }

        FCB ansFCB=null;
        //判断是不是/开头 不是就是当前目录找
        if(!path.startsWith("/")){
            // 解析所有的./和../ 约定这两种字符只出现在路径的前缀
            while(path.startsWith("./") || path.startsWith("../")){
                if(path.startsWith("./")){ // 从当前目录往下找
                    path=path.substring(2);
                }else if(path.startsWith("../")){  // 从父目录往下找
                    if(curDir!=rootDir){
                        curDir=curDir.getFather();
                    }
                    path=path.substring(3);
                }
            }
            if(path.equals("")){
                return curDir;
            }
            ansFCB = curDir;
            // 设置未定义类型，后续如果找到了目标FCB，这个类型就会被覆盖
            ansFCB.setType(Constants.U_FILE);
        }else {
            //以/开头 从根目录逐层往下找
            path = path.substring(1);
            ansFCB = rootDir;
        }
        String[] splitDir = path.split("/");
        for (String target : splitDir) {
            //找到目标文件所在目录
            for (FCB child : ansFCB.getChildren()) {
                if (child.getFileName().equals(target)) {
                    ansFCB = child;
                    break;
                }
            }
        }
        return ansFCB;
    }

    /**更新目录大小**/
    @Override
    public void updateSize(FCB fcb, Boolean isAdd, int new_add) {
        FCB temp = fcb.getFather();
        // 根目录大小不需要修改，因为整个文件树就是从根目录衍伸而出的
        // 而且也没有移动根目录的需求
        while (temp != Memory.getINSTANCE().getRootDir()){
            //自底向上修改父目录的大小
            int size = temp.getIndexNode().getSize();
            if(isAdd){
                if(new_add == -1){ // 代表覆盖写操作
                    //增加目录大小
                    temp.getIndexNode().setSize(size + fcb.getIndexNode().getSize());
                }else {   // new_add非-1，此时代表追加内容的大小
                    temp.getIndexNode().setSize(size + new_add);
                }
            }else {  // 删除文件
                temp.getIndexNode().setSize(size - fcb.getIndexNode().getSize());
            }
            temp = temp.getFather();
        }
    }


    /**显示全路径**/
    @Override
    public String pwd(FCB fcb) {
        Memory memory = Memory.getINSTANCE();
        StringBuilder sb = new StringBuilder();
        FCB temp = fcb;
        while (temp != memory.getRootDir()){
            //还没打印到根目录
            sb.insert(0,temp.getFileName());  // 头插法
            sb.insert(0,'/');
            temp = temp.getFather();
        }
        return sb.toString();
    }

    /**输入命令时显示当前目录**/
    @Override
    public void showPath() {
        Memory memory = Memory.getINSTANCE();
        StringBuilder sb = new StringBuilder();
        sb.append("\n[");
        sb.append(memory.getCurUser().getUserName()).append("@");
        sb.append(" ");
        sb.append(memory.getCurDir()==memory.getRootDir()? "/" : dirService.pwd(memory.getCurDir()));
        sb.append("]");
        System.out.print(sb);
    }

    /**显示位图**/
    @Override
    public void bitmap() {
        FAT[] fats = Memory.getINSTANCE().getFat();
        for (int i = 0; i < fats.length; i++) {
            System.out.print(fats[i].getBitmap() + " ");
            if((i+1) % Constants.BITMAP_COL == 0){
                System.out.println();
            }
        }
    }
}
