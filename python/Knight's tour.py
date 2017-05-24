# coding=utf-8
__author__ = 'BK'
'''
骑士 环游 问题
以8*8 的一位数组进行模拟
程序给出原始的地址 看看能否走出汉密尔顿环游
'''

def knight(i,j,visit,path):
    if sum(visit[0])+sum(visit[1])+sum(visit[2])+sum(visit[3])+sum(visit[4])==25:return True
    if i<0 or i>4 or j<0 or j>4 or visit[i][j]==1:return False

    path.append((i,j))
    visit[i][j]=1
    if knight(i-2,j-1,visit,path) or knight(i-2,j+1,visit,path) or knight(i-1,j-2,visit,path) or knight(i-1,j+2,visit,path) or knight(i+1,j-2,visit,path) or knight(i+1,j+2,visit,path) or knight(i+2,j-1,visit,path) or knight(i+2,j+1,visit,path):
        return True
    else:
        path.remove((i,j))
        visit[i][j]=0

visit = [[0 for i in xrange(5)]for j in xrange(5)]
path=[]
print knight(0,0,visit,path)
print path

