# coding=utf-8
__author__ = 'BK'
'''
八皇后问题是一个以国际象棋为背景的问题：
如何能够在8×8的国际象棋棋盘上放置八个皇后，
使得任何一个皇后都无法直接吃掉其他的皇后？
为了达到此目的，任两个皇后都不能处于同一条横行、纵行或斜线上。
八皇后问题可以推广为更一般的n皇后摆放问题：这时棋盘的大小变为n×n，而皇后个数也变成n。
当且仅当n = 1或n ≥ 4时问题有解
'''
class Solution(object):

    def place(self,pos,k):
        #第K个皇后
        for i in xrange(1,k):
            if pos[k]==pos[i] or abs(pos[k]-pos[i])==abs(k-i):
                return False
        return True

    def transfor(self,nums,re):
        data=[]
        for i in xrange(len(nums)):
            temp='.'*len(nums)
            temp=temp[:nums[i]-1]+'Q'+temp[nums[i]:]
            data.append(temp)

        re.append(data)
        return

    def helper(self,num,current,pos,re):

        if current > num: 
            re.append(pos[1:])
            #self.transfor(pos[1:],re)
            return
        for i in xrange(1,num+1):
            pos[current]=i
            if self.place(pos,current):
                self.helper(num,current+1,pos,re)
            else:
                pos[current]=0
        # 递归需要很高的 空间复杂性从下面一句可以看出
        # print 'gg'

    def queneN(self):
        re=[]
        self.helper(8,1,[0]*9,re)
        return len(re)


solu = Solution()
print solu.queneN()
