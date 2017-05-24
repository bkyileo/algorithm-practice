# coding=utf-8
__author__ = 'BK'
'''
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is
that adjacent houses have security system connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.
'''

'''
问题：数组a[]中不相邻元素的最大值
sum(i) = max(sum(i-1),sum(i-2)+a[i])

注意没有数组的情况
'''

def getAnswer(problems):

    count=len(problems)
    a=problems[0]
    b=max(problems[1],problems[0])

    for i in range(2,count):
        temp=b
        b=max(b,a+problems[i])
        a=temp

    print b


if __name__=='__main__':
    test=[5,4,3,2,1]
    getAnswer(test)
