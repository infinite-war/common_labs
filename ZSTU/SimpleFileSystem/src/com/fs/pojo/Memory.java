package com.fs.pojo;

import java.io.Serializable;
import java.util.List;
import java.util.Map;

/**
 * @author 陈伟剑
 * @desc 内存
 * @date 2022/12/3 13:18
 */
public class Memory implements Serializable {

    private static final long serialVersionUID = 1L;
    private static Memory INSTANCE;
    private Map<String, User> userMap; //存储在磁盘上的用户集合 从磁盘读取
    private User curUser; //当前登录用户
    private FCB curDir; //当前目录
    private FCB rootDir;  //根目录常驻内存 根目录可以引出整个文件目录 从磁盘读取
    private FAT[] fat;//文件分配表 从磁盘读取
    private List<OpenFile> openFileList; //已打开的文件集合
    private int emptyBlockNum; //空闲盘块数 从磁盘读取

    public Memory() {
    }
    public static Memory getINSTANCE() {
        if (INSTANCE == null) {
            INSTANCE = new Memory();
        }
        return INSTANCE;
    }

    public Map<String, User> getUserMap() {
        return userMap;
    }

    public void setUserMap(Map<String, User> userMap) {
        this.userMap = userMap;
    }

    public User getCurUser() {
        return curUser;
    }

    public void setCurUser(User curUser) {
        this.curUser = curUser;
    }

    public FCB getCurDir() {
        return curDir;
    }

    public void setCurDir(FCB curDir) {
        this.curDir = curDir;
    }

    public FCB getRootDir() {
        return rootDir;
    }

    public void setRootDir(FCB rootDir) {
        this.rootDir = rootDir;
    }

    public FAT[] getFat() {
        return fat;
    }

    public void setFat(FAT[] fat) {
        this.fat = fat;
    }

    public List<OpenFile> getOpenFileList() {
        return openFileList;
    }

    public void setOpenFileList(List<OpenFile> openFileList) {
        this.openFileList = openFileList;
    }

    public int getEmptyBlockNum() {
        return emptyBlockNum;
    }

    public void setEmptyBlockNum(int empty_blockNum) {
        this.emptyBlockNum = empty_blockNum;
    }
}
