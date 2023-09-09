import pyautogui

def tcui(i):
    pyautogui.click(button='left')

    pyautogui.typewrite("E900\n")
   
    filename='问题'+str(i)

    #读取文件，在内存中写微程序
    with open(filename+'的编码.txt') as f:
        while True:
            tstr = f.readline()
            if not tstr:
                break
            if '-' in tstr:
                continue
            tstr = tstr.strip('\n')
            pyautogui.typewrite(tstr)
    
    pyautogui.typewrite("\n")

    #测试
    with open(filename+'加载代码.txt') as f:
        while True:
            tstr = f.readline()
            if not tstr:
                break
            pyautogui.typewrite(tstr)


if __name__ == '__main__':
    choose=input()
    tcui(choose) 