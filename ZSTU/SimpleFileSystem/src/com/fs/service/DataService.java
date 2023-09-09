package com.fs.service;

/**
 * @author 陈伟剑
 * @desc 持久化数据操作
 * @date 2022/12/3 14:11
 */
public interface DataService {

    /**
     * 第一次运行系统则进行初始化 包括根目录 位示图 FAT表 磁盘块
     *
     */
    void init();
    /**
     * 加载数据
     *
     * @param dataPath 数据路径
     * @return {@link Boolean}
     */
    Boolean loadData(String dataPath);

    /**
     * 保存数据
     *
     * @param savePath 保存路径
     * @return {@link Boolean}
     */
    Boolean saveData(String savePath);
}
