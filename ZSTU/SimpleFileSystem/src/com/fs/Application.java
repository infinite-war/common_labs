package com.fs;

import com.fs.constant.Constants;
import com.fs.pojo.Memory;
import com.fs.service.*;
import com.fs.service.impl.*;
import com.fs.utils.Utility;
import com.fs.view.View;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Scanner;

/**
 * @author 陈伟剑
 * @desc 启动类
 * @date 2022/12/3 0:20
 */
public class Application {
    private static final DataService dataService = new DataServiceImpl();
    private static final UserService userService = new UserServiceImpl();
    private static final FileService fileService = new FileServiceImpl();
    private static final DirService dirService = new DirServiceImpl();
    private static final Scanner scanner = new Scanner(System.in);
    public static Boolean login = false;
    public static void main(String[] args) {
        //加载磁盘数据
        Boolean flag = dataService.loadData(Constants.SAVE_PATH);
        if(!flag){
            //加载失败请求初始化新的
            System.out.println("是否重新初始化一个磁盘空间（Y/N）");
            if(scanner.nextLine().equalsIgnoreCase("Y")){
                dataService.init();
            }else {
                System.exit(0);
            }
        }

        while (true){
            System.out.print("[unlogin]");
            String nextLine = scanner.nextLine();
            String[] inputs = Utility.inputResolve(nextLine);
            switch (inputs[0]){
                case "help":
                    View.unloginhelp();
                    break;
                case "login":
                    System.out.print("用户名: ");
                    String username = scanner.nextLine();
                    System.out.print("密码: ");
                    String pwd = scanner.nextLine();
                    login = userService.login(username, pwd);
                    if(login){
                        System.out.println("进入系统.....");
                        while (login){
                            dirService.showPath();
                            String nextLine2 = scanner.nextLine();
                            String[] inputs2 = Utility.inputResolve(nextLine2);
                            // 解析指令，通过反射实现(linux源码中采用函数指针实现，原理相近)
                            // 可以节省一大串的switch语句，而且增加指令也会更方便，
                            // 只需要在CommandManagement中添加对应的静态函数即可
                            CommandManagement.inputCommand(inputs2);
                        }
                    }
                    break;
                case "register":
                    System.out.print("用户名: ");
                    String username2 = scanner.nextLine();
                    System.out.print("密码: ");
                    String pwd2 = scanner.nextLine();
                    userService.register(username2,pwd2);
                    break;
                case "exit":
                    dataService.saveData(Constants.SAVE_PATH);  // 程序结束时保存数据
                    System.exit(0);
                    break;
                default:
                    System.out.println("type help to get available commands");
                    break;
            }
        }
    }



    static class CommandManagement{
        public static void inputCommand(String[] input){
            try{
                Method method=CommandManagement.class.getMethod(input[0]);
                callFunc(method, input);
            } catch (NoSuchMethodException e) {
                System.out.println("不存在相关指令，可用指令如下");
                View.help();
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
            // switch (input.length){
            //     case 1:
                    // try{
                    //     Method method=CommandManagement.class.getMethod(input[0]);
                    //     callFunc0(method);
                    // } catch (NoSuchMethodException e) {
                    //     System.out.println("不存在相关指令，可用指令如下");
                    //     View.help();
                    // } catch (Exception e) {
                    //     throw new RuntimeException(e);
                    // }
                    // break;

            //     case 2:
            //         try{
            //             Method method=CommandManagement.class.getMethod(input[0],String.class);
            //             callFunc1(method,input);
            //         } catch (NoSuchMethodException e) {
            //             System.out.println("不存在相关指令，可用指令如下");
            //             View.help();
            //         } catch (Exception e) {
            //             throw new RuntimeException(e);
            //         }
            //         break;
            //     case 3:
            //         try{
            //             Method method=CommandManagement.class.getMethod(input[0],String.class,String.class);
            //             callFunc2(method,input);
            //         } catch (NoSuchMethodException e) {
            //             System.out.println("不存在相关指令，可用指令如下");
            //             View.help();
            //         } catch (Exception e) {
            //             throw new RuntimeException(e);
            //         }
            //         break;
            //     default:
            //         System.out.println("not an available command, type 'help' to get available commands");
            }


        }

        // // 0参数指令
        // public static void callFunc0(Method method) throws Exception {
        //     method.invoke(null);
        // }

        // // 1参数指令
        // public static void callFunc1(Method method, String[] parm) throws Exception {
        //     method.invoke(null, parm[1]);
        // }

        // // 2参数指令
        // public static void callFunc2(Method method, String[] parm) throws Exception {
        //     method.invoke(null, parm[1], parm[2]);
        // }

        public static void callFunc(Method method, String... parm) throws Exception {
            String[] paramsSubset = Arrays.copyOfRange(params, 1, params.length);
            method.invoke(null, parmsSubset);
        }


        //====================具体命令========================
        public static void login(){
            userService.login(null, null);
        }

        public static void register(){
            userService.register(null,null);
        }

        public static void logout(){
            userService.logout();
            login=false;
        }

        public static void mkdir(String dirName){
            String permissionDir=Utility.inputPermission();
            dirService.mkdir(dirName,permissionDir);
        }


        public static void ll(){
            dirService.ll();
        }

        public static void pwd(){
            String path = dirService.pwd(Memory.getINSTANCE().getCurDir());
            System.out.print(path);
        }

        public static void touch(String fileName){
            String permissionFile=Utility.inputPermission();
            fileService.create(fileName,permissionFile);
        }

        public static void chmod(String fileName){
            String permission=Utility.inputPermission();
            fileService.chmod(fileName,permission);
        }

        public static void cd(String filePath){
            dirService.cd(filePath);
        }

        public static void open(String filePath){
            fileService.open(filePath);
        }

        public static void show_open(){
            fileService.show_open();
        }

        public static void close(String filePath){
            fileService.close(filePath);
        }

        public static void read(String filePath){
            fileService.read(filePath);
        }

        public static void write(String filePath){
            fileService.write(filePath);
        }


        public static void bitmap(){
            dirService.bitmap();
        }

        public static void delete(String filePath){
            fileService.delete(filePath);
        }

        public static void rename(String oldName,String newName){
            fileService.rename(oldName,newName);
        }

        public static void ls(){
            dirService.ls();
        }

        public static void help(){
            View.help();
        }

        public static void man(String command){
            View.getCommandDetail(command);
        }

//        default:
//                System.out.println("not an available command, type 'help' to get available commands");
//                                    break;
//    }
    }

}



