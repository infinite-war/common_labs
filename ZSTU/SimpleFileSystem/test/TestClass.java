import com.fs.constant.Constants;
import com.fs.pojo.Disk;

import java.io.*;

/**
 * @author infinite-war
 * @desc 测试类
 * @date 2022/11/28 16:21
 */
public class TestClass {

    public static void main(String[] args) throws IOException, ClassNotFoundException {

    }


    // 将磁盘对象持久化（放到主函数中运行）
    public static void insertObj() throws IOException {
        FileOutputStream fis=new FileOutputStream(new File(Constants.SAVE_PATH));
        ObjectOutputStream writer = new ObjectOutputStream(fis);
        writer.writeObject(new Disk());
        fis.close();
        writer.close();
    }

}
