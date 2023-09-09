package com.fs.service;

import com.fs.pojo.FCB;

/**
 * @author 陈伟剑
 * @desc 目录操作
 * @date 2022/12/3 14:52
 */
public interface DirService {
    /**
     * 显示当前目录的文件项 文件个数 文件夹大小
     * 目录/权限（自己/别人） 文件项 创建者 文件大小 修改时间    文件名
     * eg. drwx———        4     root  32     2022.12.10 a.txt
     */
    void ll();


    /**
     * 创建目录
     *
     * @param dirName    目录名
     * @param permission 权限
     * @return {@link Boolean}
     */
    Boolean mkdir(String dirName,String permission);

    /**
     * 切换目录
     * cd . 为当前目录
     * cd .. 可切换上一级
     *
     * @param dirName 目录名
     * @return {@link Boolean}
     */
    Boolean cd(String dirName);

    /**
     * 路径解析 查看是否存在该文件或目录
     *
     * @param path 路径
     * @return {@link FCB}
     */
    FCB pathResolve(String path);

    /**
     * 递归修改父目录大小
     *
     * @param fcb   FCB
     * @param isAdd 添加文件 add
     * @param new_add
     */
    void updateSize(FCB fcb,Boolean isAdd,int new_add);
    /**
     * 简略打印本目录的文件名信息
     */
    void ls();

    /**
     * 显示当前目录全路径
     * /bob/a/t.txt
     *
     * @param fcb 指定目录
     * @return {@link String} 全路径
     */
    String pwd(FCB fcb);

    /**
     * 显示当前目录
     * 如/a/b , 根目录为/
     */
    void showPath();

    /**
     * 显示位图
     * 查看盘块的分配状况
     */
    void bitmap();
}
