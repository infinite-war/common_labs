package com.fs.pojo;

import java.io.Serializable;
import java.util.Date;

/**
 * @author 陈伟剑
 * @desc 索引结点
 * @date 2022/12/3 12:30
 */


public class IndexNode implements Serializable {

    private static final long serialVersionUID = 1L;
    private String permission; //文件访问权限 6位 前三位创建者 后三位其他用户 rwx---
    private int size; //文件大小
    private int firstBlock; //文件首地址（第一个盘块号）
    private int fcbNum; //文件项个数 如果是普通文件为0 目录看其下有多少个
    private String creator; //创建者
    private Date updateTime; //文件修改时间

    public IndexNode(String permission, int size, int firstBlock, int fcbNum, String creator, Date updateTime) {
        this.permission = permission;
        this.size = size;
        this.firstBlock = firstBlock;
        this.fcbNum = fcbNum;
        this.creator = creator;
        this.updateTime = updateTime;
    }


    public String getCreator() {
        return creator;
    }

    public void setCreator(String creator) {
        this.creator = creator;
    }

    public IndexNode() {
    }

    public Date getUpdateTime() {
        return updateTime;
    }

    public void setUpdateTime(Date updateTime) {
        this.updateTime = updateTime;
    }

    public int getFcbNum() {
        return fcbNum;
    }

    public void addFcbNum() {
        this.fcbNum++;
    }
    public void subFcbNum() {
        this.fcbNum--;
    }
    public String getPermission() {
        return permission;
    }

    public void setPermission(String permission) {
        this.permission = permission;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int getFirstBlock() {
        return firstBlock;
    }

    public void setFirstBlock(int firstBlock) {
        this.firstBlock = firstBlock;
    }
}
