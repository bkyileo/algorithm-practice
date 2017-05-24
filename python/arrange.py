# coding=utf-8
__author__ = 'BK'

# 全排列生成算法

a = [1,2,3]

#递归解
def recursive(arr,begin,end):

    if begin==end:
        print arr

    else:
        for i in xrange(begin,end):
            arr[begin],arr[i]=arr[i],arr[begin]
            recursive(arr,begin+1,end)
            arr[begin],arr[i]=arr[i],arr[begin]

print recursive(a,0,3)

#字典序列
import sys
def nextA(arr):
    index=len(arr)

    for i in xrange(len(arr)-1,-1,-1):
        if arr[i] > arr[i-1]:
            index = i
            break

    if index==len(arr) or index==0:
        for i in xrange(len(arr)/2):
            arr[i],arr[len(arr)-1-i]=arr[len(arr)-1-i],arr[i]
        return

    else:
        minMax=sys.maxint
        minIndex=len(arr)

        for i in xrange(index,len(arr)):
            if arr[i] > arr[index-1] and arr[i] <= minMax:
                minMax = arr[i]
                minIndex = i

        print minIndex,index
        arr[minIndex],arr[index-1]=arr[index-1],arr[minIndex]

        # 重新排序 return
        for i in xrange(index,(len(arr)-index)/2+index):
            arr[i],arr[len(arr)-i+index-1] = arr[len(arr)-i+index-1],arr[i]

        return

'''
example of [1,2,3]

逐一插入
[1]
[1,2] [2,1]
[1,2,3][1,3,2][3,1,2] [3,2,1][2,3,1][2,1,3]
'''
def permute(nums):
    perms = [[]]
    for n in nums:
        new_perms = []
        for perm in perms:
            for i in xrange(len(perm)+1):
                new_perms.append(perm[:i] + [n] + perm[i:])   ###insert n
        perms = new_perms
    return perms


#[1,3,2] 不适用 没有办法判断 第一个元素
