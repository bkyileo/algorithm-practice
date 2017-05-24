# coding=utf-8
__author__ = 'BK'
'''
输入仅包含单组测试数据。

每组测试数据为一个3*3的矩阵，其中为0的部分表示被小Hi抹去的部分。

对于100%的数据，满足给出的矩阵至少能还原出一组可行的三阶幻方。
输出
如果仅能还原出一组可行的三阶幻方，则将其输出，否则输出“Too Many”（不包含引号）。

样例输入
0 7 2
0 5 0
0 3 0
样例输出
6 7 2
1 5 9
8 3 4
'''
def func():
    data=[]
    for i in xrange(3):
        data.append(raw_input().split())

    for i in xrange(3):
        for j in xrange(3):
            data[i][j]=int(data[i][j])

    return make(data)

def make(data):
    D={0:0,
       1:9,
       2:8,
       3:7,
       4:6,
       6:4,
       7:3,
       8:2,
       9:1}
    data[1][1]=5
    for i in xrange(3):
        for j in xrange(3):
            if data[i][j]==0:
                data[i][j]=D[data[2-i][2-j]]
    count=0
    for i in xrange(3):
        for j in xrange(3):
            if data[i][j]!=0:
                count += 1
    if count<4:
        print 'Too Many'
        return
    else:
        helper(data)
        for i in data:
            print str(i[0])+' '+str(i[1])+' '+str(i[2])

def helper(data):

    if sum(data[0])==15 and sum(data[1])==15 and sum(data[2])==15 \
            and data[0][0]+data[1][0]+data[2][0]==15 and data[0][1]+data[1][1]+data[2][1]==15 \
            and data[0][2]+data[1][2]+data[2][2]==15 and data[0][0]+data[1][1]+data[2][2]==15 \
            and data[2][0]+data[1][1]+data[0][2]==15:
        return True
    for i in xrange(3):
        for j in xrange(3):
            if data[i][j] == 0:
                for k in xrange(1,10):
                    if check(data):
                        data[i][j] = k
                        if helper(data):
                            return True
                        else:
                            data[i][j] = 0
                return False

def check(data):
    S=set()
    for i in xrange(3):
        for j in xrange(3):
            if data[i][j] in S and data[i][j] != 0:
                return False
            S.add(data[i][j])
    for i in xrange(3):
        if sum(data[i])>15:return False
    if data[0][0]+data[1][0]+data[2][0]>15:return False
    if data[0][1]+data[1][1]+data[2][1]>15:return False
    if data[0][2]+data[1][2]+data[2][2]>15:return False
    if data[0][0]+data[1][1]+data[2][2]>15:return False
    if data[2][0]+data[1][1]+data[0][2]>15:return False
    return True

a=[
[0, 7, 2],
[0, 5, 0],
[0, 3, 0]
]
helper(a)
print a
