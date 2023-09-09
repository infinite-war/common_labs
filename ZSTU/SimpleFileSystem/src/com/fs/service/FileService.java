package com.fs.service;

import com.fs.pojo.FCB;
import com.sun.org.apache.xpath.internal.operations.Bool;

import java.util.List;

/**
 * @author 陈伟剑
 * @desc 文件操作
 * @date 2022/12/3 14:11
 */
public interface FileService {

    /**
     * 创建文件
     *
     * @param fileName   文件名称
     * @param permission 权限
     * @return {@link Boolean}
     */
    Boolean create(String fileName, String permission);


    /**
     * 修改文件权限
     *
     * @param filePath   文件路径
     * @param permission 权限
     * @return {@link Boolean}
     */
    Boolean chmod(String filePath,String permission);


    /**
     * 打开文件
     *
     * @param filePath 文件路径
     * @return {@link Boolean}
     */
    Boolean open(String filePath);

    /**
     * 显示打开的文件
     */
    void show_open();

    /**
     * 读取文件
     *
     * @param filePath 文件路径
     * @return {@link Boolean}
     */
    Boolean read(String filePath);

    /**
     * 写入文件
     *
     * @param filePath 文件路径
     * @return {@link Boolean}
     */
    Boolean write(String filePath);

    /**
     * 关闭文件
     *
     * @param filePath 文件路径
     * @return {@link Boolean}
     */
    Boolean close(String filePath);

    /**
     * 删除文件
     *
     * @param filePath 文件路径
     * @return {@link Boolean}
     */
    Boolean delete(String filePath);


    /**
     * 重命名
     *
     * @param filePath 文件路径
     * @param newName  新名字
     * @return {@link Boolean}
     */
    Boolean rename(String filePath,String newName);
}
