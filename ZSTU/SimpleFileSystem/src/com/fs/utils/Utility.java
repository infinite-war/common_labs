package com.fs.utils;

import com.fs.constant.Constants;
import com.fs.pojo.FCB;
import com.fs.pojo.Memory;

import java.util.List;
import java.util.Objects;
import java.util.Scanner;

/**
 * @author 陈伟剑
 * @desc 工具类
 * @date 2022/12/3 15:05
 */
public class Utility {
    /**
     * 向上取整的除法 用于分配盘块
     *
     * @param dividend 被除数
     * @param divisor 除数
     * @return 返回 (dividend / divisor) 的向上取整结果
     */
    public static int ceilDivide(int dividend,int divisor) {
        if (dividend % divisor == 0) {
            // 整除
            return dividend / divisor;
        } else {
            // 不整除，向上取整
            return (dividend + divisor) / divisor;
        }
    }

    /**
     * 判断字符串是否为空，或者是否全是空格符
     *
     * @param str 字符串
     * @return true-为空，或者全是空格符
     */
    public static boolean isAllSpace(String str) {
        return (str == null || "".equals(str.trim()));
    }

    /**
     * 解析用户输入的命令
     *
     * @param input 用户的输入
     * @return 解析结果
     */
    public static String[] inputResolve(String input) {
        if (Utility.isAllSpace(input)) {
            return new String[]{""};
        }

        return input.trim().split("\\s+"); //匹配多个空格
    }

    /**
     * 调整控制台字体输出颜色
     *
     * @param content 内容
     * @param color  颜色
     * @param type    类型
     * @return {@link String}
     */
    public static String getFormatLogString(String content, int color, int type) {
        boolean hasType = type != 1 && type != 3 && type != 4;
        if (hasType) {
            return String.format("\033[%dm%s\033[0m", color, content);
        } else {
            return String.format("\033[%d;%dm%s\033[0m", color, type, content);
        }
    }
    /**
     * 获取文件的后缀名
     *
     * @param fileName 文件名
     * @return 后缀名
     */
    public static String getSuffix(String fileName) {
        if (fileName == null || "".equals(fileName)) {
            return "";
        }

        int index = fileName.lastIndexOf(".");
        if (index == fileName.length()-1) { // "<文件名>."这种没有后缀的文件会返回空
            return "";
        }
        return fileName.substring(index + 1);
    }


    /**
     * 检查用户输入的文件名是否符合标准
     * 目前可创建的文件名有 .txt(普通文件)、.exe(可执行文件)、.tar(压缩文件)、.zip(压缩文件)、.7z(压缩文件)
     * 文件名不可为空，不可重复
     * @param fileName String
     * @return {@link Boolean}
     */
    public static Boolean isRightFileName(String fileName, List<FCB> children) {
        //判空
        if(Objects.isNull(fileName)) {
            System.out.println("[error]: 文件名不可为空");
            return false;
        }

        //判断文件是否有后缀 && 判断是不是".<后缀>"这种只有后缀的文件
        if(!fileName.matches(".+\\..+")){
            System.out.println("[error]: 文件格式不符合要求 <文件名>.<后缀>");
            return false;
        }

        //判断是否和当前目录下的文件重名
        fileName = fileName.trim(); //去除首尾空格
        for (FCB child : children) {
            if(child.getFileName().equals(fileName)){
                System.out.println("[error]: 文件名重复,请重新命名");
                return false;
            }
        }
        return true;
    }

    /**
     * 检查用户输入的目录名是否符合标准
     * 目录名不可为空，不可重复
     * @param dirName String
     * @return {@link Boolean}
     */
    public static Boolean isRightDirName(String dirName, List<FCB> children) {
        //判空
        if(Objects.isNull(dirName)) {
            System.out.println("[error]: 目录名不可为空");
            return false;
        }

        //判断是否和当前目录下的文件重名
        dirName = dirName.trim(); //去除首尾空格
        for (FCB child : children) {
            if(child.getFileName().equals(dirName)){
                System.out.println("[error]: 目录名重复,请重新命名");
                return false;
            }
        }
        return true;
    }


    /**
     * 用户输入权限
     */
    public static String inputPermission(){
        Scanner scanner=new Scanner(System.in);
        System.out.println("请输入文件权限(必须为6位)：r:读 w:写 x:执行 -:否定对应位置的权限 [前三位表示自己] [后三位表示其他用户]");
        String permission = scanner.nextLine();
        // 权限合法性检查
        while (!Utility.isRightPermission(permission)){
            System.out.println("请输入文件权限(必须为6位)：r:读 w:写 x:执行 -:否定对应位置的权限 [前三位表示自己] [后三位表示其他用户]");
            permission = scanner.nextLine();
        }
        return permission;
    }

    /**
     * 检查用户输入的权限是否符合标准
     * 要求：权限必须有6位 位置1、4可以为'r',2、5可以为'w',3、6可以为'x'
     * 某一位若不设置需要用'-'代替
     *
     * @param permission String
     * @return {@link Boolean}
     */
    public static Boolean isRightPermission(String permission){
        // 是否有6位
        if(permission.length()!=6){
            System.out.println("[error] 权限必须为6位");
            return false;
        }
        //每一位是否符合要求
        if(!permission.matches("((r|-)(w|-)(x|-)){2}")){
            System.out.println("[error] 权限格式不符合要求");
            return false;
        }
        return true;
    }



    /**
     * 查找当前用户对该文件的权限
     *
     * @param fcb FCB
     * @return int 0表示无权限 r=4,w=2,x=1 rwx=7 rw-=6 r--=4
     */
    public static int checkPermission(FCB fcb){
        int permission = 0;
        //查看是否是创建者
        String per = null;
        if(Memory.getINSTANCE().getCurUser().getUserName().equals(fcb.getIndexNode().getCreator())){
            //前三位
            per = fcb.getIndexNode().getPermission().substring(0,3);
        }else {
            //后三位
            per = fcb.getIndexNode().getPermission().substring(3);
        }
        char[] chars = per.toCharArray();
        for (char c : chars) {
            if(c == 'r'){
                permission += Constants.READ;
            }else if(c == 'w'){
                permission += Constants.WRITE;
            }else if(c == 'x'){
                permission += Constants.EXECUTION;
            }
        }
        return permission;
    }

}
