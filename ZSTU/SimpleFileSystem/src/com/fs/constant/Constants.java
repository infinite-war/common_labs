package com.fs.constant;


/**
 * @author 陈伟剑
 * @desc 常量类
 * @date 2022/11/30 16:21
 */
public interface Constants {
    String SAVE_PATH = "./resource/diskObject/system.data"; //系统文件保存位置

    Character D_FILE='D'; //目录文件类型
    Character C_FILE='C'; //普通文件类型
    Character U_FILE='U'; //未定义文件类型
    int BLOCK_COUNT = 256; //磁盘块数
    int BLOCK_SIZE = 8; //块大小 单位B
    int BITMAP_COL = 16; //位示图列数

    int ALL_PERMISSION = 7; //完整权限
    int READ_AND_WRITE=6; //读写权限
    int READ = 4; //读权限
    int WRITE = 2; //写权限
    int EXECUTION = 1; //执行权限

    int NO_PERMISSION=0; //无权限


    String ERROR="[error]: ";  // 错误提示
    String SUCCESS="[success]: ";  // 成功提示
}
