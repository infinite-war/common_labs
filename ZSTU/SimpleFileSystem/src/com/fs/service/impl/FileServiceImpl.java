package com.fs.service.impl;

import com.fs.constant.Constants;
import com.fs.pojo.*;
import com.fs.service.DirService;
import com.fs.service.DiskService;
import com.fs.service.FileService;
import com.fs.utils.Utility;

import java.util.Date;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

/**
 * @author 陈伟剑
 * @desc 文件操作实现类
 * @date 2022/12/3 15:14
 */
public class FileServiceImpl implements FileService {
    private static final DirService dirService = new DirServiceImpl();
    private static final DiskService diskService = new DiskServiceImpl();
    private static final Scanner scanner = new Scanner(System.in);

    /**创建文件**/
    @Override
    public Boolean create(String fileName,String permission) {
        FCB curDir = Memory.getINSTANCE().getCurDir();
        User user = Memory.getINSTANCE().getCurUser();
        List<FCB> children = curDir.getChildren();

        if(!Utility.isRightFileName(fileName,children)){
            return false;
        }

        //创建索引节点 创建FCB 文件大小为0 空文件
        IndexNode indexNode = new IndexNode(permission, 0, -1, 0, user.getUserName(), new Date());
        FCB fcb = new FCB(fileName, Constants.C_FILE, indexNode, curDir, null);
        //将文件控制块放入磁盘的fcb集合
        Disk.getINSTANCE().getFcbList().add(fcb);
        //修改父目录的文件项 加入父目录儿子集合
        curDir.getIndexNode().addFcbNum();
        curDir.getChildren().add(fcb);
        System.out.println("[success]: 创建文件成功");
        return true;
    }



    @Override
    /**修改文件权限**/
    public Boolean chmod(String filePath,String permission){
        // 找到要修改权限的目标文件
        FCB fcb=dirService.pathResolve(filePath);
        if(fcb.getType()==Constants.U_FILE){
            System.out.println("[error]: 目标文件不存在");
            return false;
        }
        // 判断是不是文件的创建者
        if(!Objects.equals(fcb.getIndexNode().getCreator(), Memory.getINSTANCE().getCurUser().getUserName())){
            System.out.println(Constants.ERROR+"你不是这个文件的创建者，无法修改文件权限");
            return false;
        }

        // 文件是否处于打开状态，若处于打开状态则关闭
        for (OpenFile openFile : Memory.getINSTANCE().getOpenFileList()) {
            if(openFile.getFcb()==fcb){
                System.out.println(Constants.ERROR+"文件处于打开状态");
            }
        }

        // 确认修改权限
        String choice;
        while (true){
            System.out.println("确认修改该文件的权限？（Y/N）");
            choice = scanner.nextLine();
            if(choice.equals("Y") || choice.equals("y")) break;
            if(choice.equals("N") || choice.equals("n")) {
                System.out.println(Constants.SUCCESS+"已取消权限修改");
                return false;
            }
        }

        fcb.getIndexNode().setPermission(permission);

        System.out.println(Constants.SUCCESS+"权限修改成功");
        return true;
    }


    @Override
    /**打开文件**/
    public Boolean open(String filePath) {
        //使用pathResolve解析
        FCB fcb = dirService.pathResolve(filePath);
        //null 不存在
        if(Objects.isNull(fcb) || fcb.getType().equals(Constants.U_FILE)){
            System.out.println("[error]: 目标文件不存在");
            return false;
        }else if(fcb.getType().equals(Constants.D_FILE)){
            //type D 不是普通文件
            System.out.println("[error]: 无法打开目录文件");
            return false;
        }else {
            //type N 普通文件
            //判断权限
            int permission = Utility.checkPermission(fcb);
            if(permission == 0){
                System.out.println("[error]: 无权限");
                return false;
            }
            //判断是否已经打开
            //判断是否已经在openFileList中
            String fullPath = dirService.pwd(fcb);
            OpenFile toAddFile = isFileOpening(fcb);
            if(Objects.nonNull(toAddFile)){
                System.out.println("[error]: 文件已打开");
                return false;
            }
            //加入openFileList中
            OpenFile openFile = new OpenFile(fcb, fullPath);
            Memory.getINSTANCE().getOpenFileList().add(openFile);
            System.out.println("[success]: 打开成功");
            return true;
        }
    }

    @Override
    /**显示打开文件**/
    public void show_open() {
        if(Memory.getINSTANCE().getOpenFileList().size() == 0){
            System.out.println("<没有打开的文件>");
        }
        for (int i = 0; i < Memory.getINSTANCE().getOpenFileList().size(); i++) {
            System.out.print(Memory.getINSTANCE().getOpenFileList().get(i).getFcb().getFileName() + "\t");
        }
    }


    @Override
    public Boolean read(String filePath) {
        //判断是否存在
        FCB fcb = dirService.pathResolve(filePath);
        if(Objects.isNull(fcb)){
            System.out.println("[error]: 目标文件不存在");
            return false;
        }else if(fcb.getType().equals(Constants.D_FILE)){
            //type D 不是普通文件
            System.out.println("[error]: 无法写目录文件");
            return false;
        }else {
            //type N 普通文件
            //判断文件权限
            int permission = Utility.checkPermission(fcb);

            if((permission&Constants.READ)!=Constants.READ){   // `按位与`操作，查看读权限
                System.out.println("[error]: 无读权限");
                return false;
            }
            //判断是否在openFileList中
            OpenFile toReadFile = isFileOpening(fcb);
            if(Objects.nonNull(toReadFile)){
                FAT[] fats = Memory.getINSTANCE().getFat();
                Block[] disk = Disk.getINSTANCE().getDisk();
                //从磁盘读取
                System.out.println("--------BEGIN--------");
                if(fcb.getIndexNode().getSize() == 0){
                    System.out.println("<----EMPTY FILE----->");
                    System.out.println("---------END---------");
                    return false;
                }
                FAT temp = fats[fcb.getIndexNode().getFirstBlock()];
                while (temp.getNextId() != -1){
                    //遍历输出
                    System.out.print(disk[temp.getId()].getContent());
                    temp = fats[temp.getNextId()];
                }
                System.out.print(disk[temp.getId()].getContent());
                System.out.println();
                System.out.println("---------END---------");
            }else {
                System.out.println("[error]: 文件未处于打开状态(先通过open打开文件)");
                return false;
            }
        }
        return true;
    }

    @Override
    /**写入文件**/
    public Boolean write(String filePath) {
        //判断是否存在
        FCB fcb = dirService.pathResolve(filePath);
        if(Objects.isNull(fcb)){
            System.out.println("[error]: 目标文件不存在");
            return false;
        }else if(fcb.getType().equals(Constants.D_FILE)){
            //type D 不是普通文件
            System.out.println("[error]: 无法写目录文件");
            return false;
        }else if(Utility.getSuffix(fcb.getFileName()).matches("(exe|tar|zip|7z|rar)")){
            System.out.println("[error]: 此文件为压缩文件或可执行文件，无法直接写入");
            return false;
        } else {
            //type N 普通文件
            //判断文件权限
            int permission = Utility.checkPermission(fcb);
            if(permission == Constants.READ){
                System.out.println("[error]: 该文件是只读文件");
                return false;
            }else if((permission&Constants.WRITE) != Constants.WRITE){
                System.out.println("[error]: 无写权限");
                return false;
            }else {
                //可写
                //判断是否在openFileList中
                OpenFile toWriteFile = isFileOpening(fcb);
                if(Objects.nonNull(toWriteFile)){
                    StringBuilder content = new StringBuilder();
                    System.out.println("请输入要写入的内容（以$$结尾）:");
                    //获取用户输入 输入$$结束
                    while (true){
                        String nextLine = scanner.nextLine();
                        if(nextLine.endsWith("$$")){
                            content.append(nextLine,0,nextLine.length()-2);
                            break;
                        }else {
                            content.append(nextLine);
                            content.append("\n");
                        }
                    }
                    String choice;
                    if(fcb.getIndexNode().getSize() == 0){
                        //空文件 默认覆盖
                        choice = "1";
                    }else {
                        //有内容 让用户选择写入模式
                        do {
                            System.out.println("原文件有内容 请选择覆盖写（1）/ 追加写（2）:");
                            choice = scanner.nextLine();
                        } while (!choice.equals("1") && !choice.equals("2"));
                    }
                    FAT[] fats = Memory.getINSTANCE().getFat();
                    int size = content.toString().toCharArray().length;
                    switch (choice){
                        case "1":
                            //覆盖写入
                            //1.如果不是空文件 则清空之前占据的盘块
                            if(fcb.getIndexNode().getSize() != 0){
                                diskService.freeFile(fcb);
                            }
                            //2.重新写入
                            int first = diskService.writeToDisk(content.toString());
                            if(first==-1){
                                return false;
                            }
                            //3.将文件指向第一块
                            fcb.getIndexNode().setFirstBlock(first);
                            //4.修改索引结点大小
                            fcb.getIndexNode().setSize(size);
                            //5.修改父目录项 自底向上修改父目录的大小
                            dirService.updateSize(fcb,true,-1);
                            break;

                        case "2":
                            //追加写入
                            //1.从第一块往下找  直到-1的块的块号
                            FAT temp = fats[fcb.getIndexNode().getFirstBlock()];
                            while (temp.getNextId() != -1){
                                temp = fats[temp.getNextId()];
                            }
                            // temp追加

                            //2.写入要追加的内容
                            content.insert(0,'\n');
                            int appendBegin = diskService.writeToDisk(content.toString());
                            if(appendBegin==-1){
                                return false;
                            }
                            //3.修改最后一块指向新的内容
                            temp.setNextId(appendBegin);
                            //4.修改索引结点大小 加上原来的
                            int originSize = fcb.getIndexNode().getSize();   // 原文件的大小
                            fcb.getIndexNode().setSize(originSize + size);   // 新文件的大小
                            //修改父目录项 以及一直递归修改父目录的大小
                            dirService.updateSize(fcb,true,size);
                            break;
                        default:
                            break;
                    }
                    System.out.println("[success]: 写入成功！");
                    return true;
                }else {
                    System.out.println("[error]: 文件未打开 请先打开！");
                    return false;
                }
            }
        }
    }

    @Override
    /**关闭文件**/
    public Boolean close(String filePath) {
        //判断是否存在
        FCB fcb = dirService.pathResolve(filePath);
        if(Objects.isNull(fcb)){
            System.out.println("[error]: 目标文件不存在");
            return false;
        }else if(fcb.getType().equals(Constants.D_FILE)){
            //type D 不是普通文件
            System.out.println("[error]: 无法关闭目录文件");
            return false;
        }else {
            //type N 普通文件
            //判断是否在openFileList中
            String fullPath = dirService.pwd(fcb);
            List<OpenFile> openFileList = Memory.getINSTANCE().getOpenFileList();
            for (OpenFile openFile : openFileList) {
                if(openFile.getFilePath().equals(fullPath)){
                    //修改fcb的updateTime
                    fcb.getIndexNode().setUpdateTime(new Date());
                    //从openFileList中移除
                    openFileList.remove(openFile);
                    System.out.println("[success]: 文件关闭成功");
                    return true;
                }
            }
            System.out.println("[error]: 文件未打开,无需关闭");
            return false;
        }
    }

    @Override
    /**删除文件**/
    public Boolean delete(String filePath) {
        //判断是否存在
        FCB fcb = dirService.pathResolve(filePath);
        if(Objects.isNull(fcb)){
            System.out.println("[error]: 目标文件不存在");
            return false;
        }
        //判断权限 需要对目录具有rwx权限 对文件具有rw权限
        //假设用户b进入了用户a的用户目录下(a将自己的目录设置为他人可读)，那么用户b不能删除a用户目录下的文件
        int per_father = Utility.checkPermission(fcb.getFather());
        int permission = Utility.checkPermission(fcb);
        if(!(per_father == Constants.ALL_PERMISSION
                && (permission == Constants.ALL_PERMISSION || permission == Constants.READ_AND_WRITE))){
            System.out.println("[error]: 无权限");
            return false;
        }
        //判断是否处于打开状态。若处于打开，则要要先关闭
        //判断是否在openFileList中
        OpenFile toWriteFile = isFileOpening(fcb);

        if(Objects.nonNull(toWriteFile)){
            System.out.println("[error]: 文件被打开,请先关闭");
            return false;
        }
        //重复确认
        String choice;
        while (true){
            System.out.println("确认删除该文件？（Y/N）");
            choice = scanner.nextLine();
            if(choice.equals("Y") || choice.equals("y")) break;
            if(choice.equals("N") || choice.equals("n")) {
                System.out.println("[success]: 已取消删除！");
                return false;
            }
        }
        //空文件判断
        if(fcb.getIndexNode().getSize() != 0 || fcb.getIndexNode().getFcbNum() != 0){
            if(fcb.getType().equals(Constants.D_FILE)){  // 不是空文件就需要递归删除下面的子文件
                //type D 目录
                //递归删除不大好实现。
                // 存在这样一种情况：用户对删除的目录有权限，但是对目录里面的文件没有权限，不能无差别删除
//                diskService.freeDir(fcb);
//                List<FCB> children=fcb.getChildren();
//
//                for (FCB fcb1 : children) {
//                    delete(fcb1.getFileName());    //递归删除
//                }

                System.out.println("[error]: 目录非空,无法删除");
                return false;
            }else {
                //清空磁盘
                diskService.freeFile(fcb);
            }
        }
        //不能删除当前所在的目录
        if(fcb == Memory.getINSTANCE().getCurDir()){
            System.out.println("[error]: 无法删除当前目录,请先退出当前目录");
        }
        //从FCB集合中去除 修改父目录文件项 修改父目录儿子结点
        Disk.getINSTANCE().getFcbList().remove(fcb);
        fcb.getFather().getIndexNode().subFcbNum();
        fcb.getFather().getChildren().remove(fcb);
        //递归修改父目录文件大小
        dirService.updateSize(fcb,false,-1);
        System.out.println("[success]: 删除成功");
        return true;
    }

    private OpenFile isFileOpening(FCB fcb){
        String fullPath = dirService.pwd(fcb);
        List<OpenFile> openFileList = Memory.getINSTANCE().getOpenFileList();
        OpenFile targetFCB = null;
        for (OpenFile openFile : openFileList) {
            if(openFile.getFilePath().equals(fullPath)){
                targetFCB = openFile;
            }
        }
        return targetFCB;
    }


    @Override
    /**文件重命名**/
    public Boolean rename(String filePath, String newName) {
        //判断是否存在
        FCB fcb = dirService.pathResolve(filePath);
        if(Objects.isNull(fcb)){
            System.out.println("[error]: 目标文件不存在");
            return false;
        }
        //判断文件权限
        int permission = Utility.checkPermission(fcb);
        if(permission == Constants.NO_PERMISSION
                || (permission & Constants.READ)!= Constants.READ){
            System.out.println("[error]: 无权限");
            return false;
        }
        //如果是普通文件 判断是否打开
        if(fcb.getType().equals(Constants.C_FILE)){
            String fullPath = dirService.pwd(fcb);
            List<OpenFile> openFileList = Memory.getINSTANCE().getOpenFileList();
            OpenFile toRenameFile = null;
            for (OpenFile openFile : openFileList) {
                if(openFile.getFilePath().equals(fullPath)){
                    toRenameFile = openFile;
                    break;
                }
            }
            if(Objects.nonNull(toRenameFile)){
                System.out.println("[error]: 文件被打开,请先关闭！");
                return false;
            }
            //判断一下新文件名格式是否符合规范
            //函数中已经实现重命名判定
            if(!Utility.isRightFileName(newName,fcb.getFather().getChildren())){
                return false;
            }
        }else{
            //如果是目录文件
            //函数中已经实现重命名判定
            if(!Utility.isRightDirName(newName,fcb.getFather().getChildren())){
                return false;
            }
        }

        //进行重命名
        fcb.setFileName(newName);
        System.out.println("[success]: 文件名修改成功");
        return true;
    }
}
