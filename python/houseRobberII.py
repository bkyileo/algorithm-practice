# coding=utf-8
__author__ = 'BK'
'''
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his
thievery so that he will not get too much attention.
This time, all houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one.
Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
'''
def getAnswer(problems):

    count=len(problems)
    a=problems[0]
    b=max(problems[1],problems[0])

    for i in range(2,count):
        temp=b
        b=max(b,a+problems[i])
        a=temp
    return b

if __name__=='__main__':
    test=[5,4,3,2,1,3,1]
    #print  max(getAnswer(test[1:]),getAnswer(test[0:len(test)-1]))
    test=[1]
    print max(test)