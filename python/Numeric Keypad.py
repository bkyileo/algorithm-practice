# coding=utf-8
__author__ = 'BK'
'''
The numberic keypad on your mobile phone looks like below:

1 2 3
4 5 6
7 8 9
  0
Suppose you are holding your mobile phone with single hand. Your thumb points at digit 1.
Each time you can 1) press the digit your thumb pointing at, 2) move your thumb right,
3) move your thumb down. Moving your thumb left or up is not allowed.

By using the numeric keypad under above constrains, you can produce some numbers like 177 or 480
while producing other numbers like 590 or 52 is impossible.

Given a number K, find out the maximum number less than or equal to K that can be produced.

输入
The first line contains an integer T, the number of testcases.

Each testcase occupies a single line with an integer K.



For 50% of the data, 1 <= K <= 999.

For 100% of the data, 1 <= K <= 10500, t <= 20.

输出
For each testcase output one line, the maximum number less than or equal to the corresponding K that can be produced.

样例输入
3
25
83
131
样例输出
25
80
129
'''


def dfs(phone,x,y,path,lenth,re):
        if lenth==0:
            re.add(path)
            return
        if phone[x][y]==None:
            return
        dfs(phone,x+1,y,path,lenth,re)
        dfs(phone,x,y+1,path,lenth,re)

        path = path*10 + phone[x][y]
        dfs(phone,x+1,y,path,lenth-1,re)
        dfs(phone,x,y+1,path,lenth-1,re)
def solution():
    nums = int(raw_input())
    phone=[[1,2,3,None],
           [4,5,6,None],
           [7,8,9,None],
           [None,0,None],
           [None,None,None]]
    re=set()
    dfs(phone,0,0,0,1,re)
    dfs(phone,0,0,0,2,re)
    dfs(phone,0,0,0,3,re)
    dfs(phone,0,0,0,4,re)
    dfs(phone,0,0,0,5,re)

    re=list(re)

    for i in xrange(nums):
        k=int(raw_input())
        re.insert(0,k+1)
        re.sort()
        print re[re.index(k+1)-1]
        re.remove(k+1)
solution()