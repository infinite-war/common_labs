import xlrd
import pandas as pd


def f_16_to_2(file_from, file_to):  
    #从file_from.txt文件中读取十六进制的指令，转换成二进制，然后放在file_to.xlsx
    table = {
        '0' : "0000",
        '1' : "0001",
        '2' : "0010",
        '3' : "0011",
        '4' : "0100",
        '5' : "0101",
        '6' : "0110",
        '7' : "0111",
        '8' : "1000",
        '9' : "1001",
        'A' : "1010",
        'B' : "1011",
        'C' : "1100",
        'D' : "1101",
        'E' : "1110",
        'F' : "1111",
    }
    with open(file_from, 'r') as f:
        dic = {}
        for i in range(56):
            #i
            #[]
            dic[i] = []
        
        while True:
            str = f.readline()
            if not str:
                break
            res = ""
            for c in str.strip('\n'):
                if c == ' ':
                    continue
                res += table[c]
            #print(res)  #至此翻译成了一个又一个二进制串
            for i in range(len(res)):
                dic[i].append(res[i])
        #至此dic就是表格中的内容
        df = pd.DataFrame(dic)
        df.to_excel(file_to)

def f_2_to_16(file_from, file_to, kw):
    mp = {
        0 : '0',
        1 : '1',
        2 : '2',
        3 : '3',
        4 : '4',
        5 : '5',
        6 : '6',
        7 : '7',
        8 : '8',
        9 : '9',
        10 : 'A',
        11 : 'B',
        12 : 'C',
        13 : 'D',
        14 : 'E',
        15 : 'F'
    }
    f = open(file_to, "w")
    data = xlrd.open_workbook(file_from)
    table = data.sheets()[0]
    
    for row in range(4 , table.nrows, kw):
        f.write(table.cell_value(row, 1))
        f.write(" : \n")
        res = ''
        for col in range(2, table.ncols):
            res += str(table.cell_value(row, col))[0]
            #print(len(str(table.cell_value(row, col))))
        #至此res即为这个16进制串
        res_ = ""
        
        for i in range(0, len(res), 4):
            num = int(res[i]) * 8 + int(res[i + 1]) * 4 + int(res[i + 2]) * 2 + int(res[i + 3]) * 1
            res_ += mp[num]
        res_ = "00" + res_
        res__ = ""
        for i in range(len(res_)):
            res__ += res_[i]
            if i % 4 == 3:
                res__ += ' '
        f.write(res__)
        f.write('\n')
    f.close()


if __name__ == '__main__':
    f_2_to_16('问题1的编码.xlsx', '问题1的编码.txt', 2)
    f_2_to_16('问题2的编码.xlsx', '问题2的编码.txt', 1)
    f_2_to_16('问题3的编码.xlsx', '问题3的编码.txt', 1)