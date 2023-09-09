package com.fs.service.impl;

import com.fs.constant.Constants;
import com.fs.pojo.*;
import com.fs.service.DataService;
import com.fs.service.DirService;
import com.fs.service.FileService;
import com.fs.service.UserService;

import javax.jws.soap.SOAPBinding;
import java.util.*;

/**
 * @author 陈伟剑
 * @desc 用户操作实现类
 * @date 2022/12/3 15:15
 */
public class UserServiceImpl implements UserService {

    private static final DataService dataService = new DataServiceImpl();
    private static final FileService fileService = new FileServiceImpl();
    private static final Scanner scanner = new Scanner(System.in);
    Memory instance = Memory.getINSTANCE();
    @Override
    public Boolean login(String userName, String password) {
        //判断当前是否登录
        if(Objects.nonNull(instance.getCurUser())){
            System.out.println("[error]:请先退出登录");
            return false;
        }
        //用户名或密码错误
        User user = instance.getUserMap().get(userName);
        if(Objects.isNull(user) || !user.getPassword().equals(password)){
            System.out.println("[error]:用户名或密码错误");
            return false;
        }
        //设置memory量
        //找到用户目录的FCB
        // 约定用户目录存在根目录下。
        // 比如，用户a有一个目录a，其他用户(或者用户a)的目录下其实也可以创建文件名为a的目录
        // 这时候，寻找用户目录时就要额外判断一下目改录的是不是在根目录下
        List<FCB> fcbList = Disk.getINSTANCE().getFcbList();
        for (FCB curFcb : fcbList) {
            if (curFcb.getFileName().equals(userName)
                    && curFcb.getFather().equals(Memory.getINSTANCE().getRootDir())) {
                //用户目录FCB
                instance.setCurUser(user);
                instance.setCurDir(curFcb);
            }
        }
        System.out.println("[success]登录成功,上一次登录时间："+user.getLastLoginTime());
        user.setLastLoginTime(new Date());
        return true;
    }

    @Override
    public Boolean register(String userName, String password) {
        //判断是否处于登录状态
        if (Objects.nonNull(instance.getCurUser())) {
            System.out.println("[error]: 请先退出登录");
            return false;
        }
        Map<String, User> userMap = instance.getUserMap();
        //判断用户名是否重复
        if(Objects.nonNull(userMap.get(userName))){
            System.out.println("[error]: 用户名重复");
            return false;
        }
        //放入用户集合
        userMap.put(userName,new User(userName,password,null));

        //新建一个用户目录的FCB及索引结点 其他用户无权限进入
        FCB rootDir = instance.getRootDir();
        IndexNode indexNode = new IndexNode("rwx---",0,-1,0,userName,new Date());
        FCB userFCB = new FCB(userName, Constants.D_FILE,indexNode, rootDir,new LinkedList<>());
        //放进总fcb集合
        Disk.getINSTANCE().getFcbList().add(userFCB);
        //修改根目录
        rootDir.getChildren().add(userFCB);
        rootDir.getIndexNode().addFcbNum();
        System.out.println("[success]:注册成功");
        return true;
    }

    @Override
    public Boolean logout() {
        // 判断
        if(Objects.isNull(instance.getCurUser())){
            System.out.println("[error]: 未处于登录状态");
            return false;
        }

        // 关闭所有文件
        if(Memory.getINSTANCE().getOpenFileList().size()>0){

            String choice = null;
            while (true){
                System.out.println("当前有文件未关闭，强制退出将关闭所有的文件，确认退出？(Y/N)");
                choice = scanner.nextLine();
                if(choice.equals("Y") || choice.equals("y")) break;
                if(choice.equals("N") || choice.equals("n")) {
                    System.out.println("[success]: 已取消退出");
                    return false;
                }
            }

            List<OpenFile> openFileList = Memory.getINSTANCE().getOpenFileList();
            List<String> filePaths=new ArrayList<>();
            for(OpenFile openFile:openFileList){
                filePaths.add(openFile.getFilePath());
            }
            for (String filePath : filePaths) {
                fileService.close(filePath);
                System.out.println("关闭了文件"+filePath);
            }
        }

        instance.setCurUser(null);
        instance.setCurDir(instance.getRootDir());
        instance.getOpenFileList().clear();

        // 退出时保存数据
        dataService.saveData(Constants.SAVE_PATH);
        return true;
    }
}
