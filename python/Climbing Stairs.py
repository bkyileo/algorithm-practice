# coding=utf-8
__author__ = 'BK'
'''
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
'''

def getAnswer(n):

    a,b=0,1
    for i in range(n):
        a,b=b,a+b
    return b

'''
1:1 (1)
2:1-1,2 (2)
3:1-1-1,1-2,2-1 (3)
4:1-1-1-1,1-2-1,2-1-1,1-1-2,2-2 (5)
5:1-1-1-1-1,1-1-1-2,1-1-2-1,1-2-1-1,2-1-1-1,2-2-1,2-1-2,1-2-2 (8)
'''
if __name__=='__main__':

    print getAnswer(4)

