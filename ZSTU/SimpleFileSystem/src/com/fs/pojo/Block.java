package com.fs.pojo;

import java.io.Serializable;

/**
 * @author 陈伟剑
 * @desc 物理盘块
 * @date 2022/12/3 12:42
 */
public class Block implements Serializable {

    private static final long serialVersionUID = 1L;
    private int id; //块号
    private int blockSize; //块大小
    private String content; //块内容

    public Block(int id, int blockSize, String content) {
        this.id = id;
        this.blockSize = blockSize;
        this.content = content;
    }

    public Block() {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getBlockSize() {
        return blockSize;
    }

    public void setBlockSize(int blockSize) {
        this.blockSize = blockSize;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public String toString() {
        return "Block{" +
                "id=" + id +
                ", blockSize=" + blockSize +
                ", content='" + content + '\'' +
                '}';
    }
}
