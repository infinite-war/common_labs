package com.fs.view;

import com.fs.pojo.FCB;
import com.fs.pojo.IndexNode;
import com.fs.pojo.Memory;
import com.fs.utils.Utility;

import java.lang.reflect.Method;

/**
 * @author 陈伟剑
 * @desc 展示交互类
 * @date 2022/12/3 15:06
 */
public class View {

    public static void unloginhelp(){
        System.out.println("=====command======");
        System.out.println("<login> 登录");
        System.out.println("<register> 注册");
        System.out.println("<logout> 退出");
    }
    public static void help(){
        System.out.println("=====command======");
        System.out.println("login 登录(先退出当前用户)");
        System.out.println("register 注册(先退出当前用户)");
        System.out.println("logout 退出");
        System.out.println("mkdir [dirName] 创建目录");
        System.out.println("cd [fileName] 切换到指定目录");
        System.out.println("touch [fileName] 创建文件");
        System.out.println("chmod [fileName] 修改文件权限");
        System.out.println("rename [filePath] [newName] 文件重命名");
        System.out.println("open [fileName] 打开文件");
        System.out.println("close [fileName] 关闭文件");
        System.out.println("read [fileName] 读文件");
        System.out.println("write [fileName] 写文件");
        System.out.println("delete [fileName] 删除文件");
        System.out.println("show_open 显示打开的文件");
        System.out.println("bitmap 显示位示图");
        System.out.println("ls 显示目录文件名");
        System.out.println("ll 显示当前目录下所有文件详细信息");
        System.out.println("man [command] 显示指令详细信息");
        System.out.println("=====command======");
    }
    public static void showFcb(FCB fcb,int color){
        IndexNode indexNode = fcb.getIndexNode();
        System.out.printf("%-1s%-6s\t  %-2d\t  %-5s\t  %-3d\t%28s\t%-8s",
                fcb.getType(),
                indexNode.getPermission(),
                indexNode.getFcbNum(),
                indexNode.getCreator(),
                indexNode.getSize(),
                indexNode.getUpdateTime(),
                color == -1? fcb.getFileName() : Utility.getFormatLogString(fcb.getFileName(),color,0));
        System.out.println();
    }



    // 利用java反射机制动态调用函数方法，类似于c的函数指针
    public static void getCommandDetail(String command){
        try{
            Method method=View.class.getMethod(command);
            callFunc(method);
        } catch (NoSuchMethodException e) {
            System.out.println("不存在相关指令，可用指令如下");
            View.help();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * 通用的调用函数
     * @param method
     */
    public static Void callFunc(Method method) throws Exception{
        return (Void)method.invoke(null);
    }


    // ==========================================man查看具体信息=======================================================
    public static void login(){
        System.out.println("命令 login");
        System.out.println("格式: \n\tlogin(enter)");
        System.out.println("\t用户名:(键盘输入后，enter确认)\n\t密码:(键盘输入后，enter确认)");
        System.out.println("输入指令后按提示输入用户名和密码");
        System.out.println("需要先退出当前用户");
    }

    public static void register(){
        System.out.println("命令 register");
        System.out.println("格式: \n\tregiter(enter)");
        System.out.println("\t用户名:(键盘输入后，enter确认)\n\t密码:(键盘输入后，enter确认)");
        System.out.println("按提示输入用户名和密码");
        System.out.println("要处于未登录状态");
    }

    public static void logout(){
        System.out.println("命令 logout");
        System.out.println("格式: \n\tlogout");
        System.out.println("退出账号");
        System.out.println("要处于登录状态");
        System.out.println("退出前会关闭所有处于打开状态的文件");
    }

    public static void mkdir(){
        System.out.println("命令 mkdir");
        System.out.println("格式: \n\tmkdir [dirName] 创建目录");
        System.out.println("创建目录，支持路径输入");
    }

    public static void cd(){
        System.out.println("命令 cd");
        System.out.println("格式: \n\tmkdir [dirName] 创建目录");
        System.out.println("切换当前目录");
    }

    public static void touch(){
        System.out.println("命令 touch");
        System.out.println("格式: \n\ttouch [fileName]");
        System.out.println("创建普通文件");
        System.out.println("普通文件名必须带后缀，<文件名>.<后缀名>");
    }

    public static void chmod(){
        System.out.println("命令 chmod");
        System.out.println("格式: \n\tchmod [fileName]");
        System.out.println("修改文件权限");
        System.out.println("只有当前文件的创建者才能修改对应的文件权限");
    }

    public static void rename(){
        System.out.println("命令 rename");
        System.out.println("格式: \n\trename [fileName]");
        System.out.println("重命名文件");
        System.out.println("需要读权限");
    }

    public static void open(){
        System.out.println("命令 open");
        System.out.println("格式: \n\topen [fileName]");
        System.out.println("打开普通文件");
        System.out.println("支持路径输入");
        System.out.println(".rar、.7z、.exe等压缩文件或可执行文件无法打开");
    }

    public static void close(){
        System.out.println("命令 close");
        System.out.println("格式: \n\tclose [fileName]");
        System.out.println("关闭普通文件");
        System.out.println("支持路径输入");
        System.out.println("文件需要处于打开状态");
    }

    public static void read(){
        System.out.println("命令 read");
        System.out.println("格式: \n\tread [fileName]");
        System.out.println("文件读操作");
        System.out.println("文件需要处于打开状态");
    }

    public static void write(){
        System.out.println("命令 write");
        System.out.println("格式: \n\twrite [fileName]");
        System.out.println("文件写操作");
        System.out.println("文件需要处于打开状态");
        System.out.println("支持覆盖写和追加写");
    }

    public static void delete(){
        System.out.println("命令 delete");
        System.out.println("格式: \n\tdelete [fileName]");
        System.out.println("删除文件");
        System.out.println("支持路径输入");
        System.out.println("不支持删除非空目录");
    }

    public static void show_open(){
        System.out.println("命令 show_open");
        System.out.println("格式: \n\tshow_open [fileName]");
        System.out.println("显示处于打开状态的文件");
    }

    public static void bitmap(){
        System.out.println("命令 bitmap");
        System.out.println("格式: \n\tbitmap");
        System.out.println("显示当前盘块的占用状况");
    }

    public static void ls(){
        System.out.println("命令 ls");
        System.out.println("格式: \n\tls");
        System.out.println("显示当前目录下所有文件的简要信息");
    }

    public static void ll(){
        System.out.println("命令 ll");
        System.out.println("格式: \n\tll");
        System.out.println("显示当前目录下所有文件的具体信息");
        System.out.println("具体信息包括:");
        System.out.println("\t目录权限 子文件项数 创建者 文件大小 修改时间 文件名");
    }

    public static void man(){
        System.out.println("命令 man");
        System.out.println("格式: \n\tman [command]");
        System.out.println("显示指令的详细信息");
    }

}
