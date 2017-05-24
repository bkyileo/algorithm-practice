# coding=utf-8
__author__ = 'BK'
'''
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
'''
class Solution(object):

    # 第一种方法：使用dfs的方法 给出数组当前访问的位置 当前的temp[] 递归下一层
    def helper(self,nums,current,k,re,temp):

        if k==0:
            re.append(temp)
            return

        if current==len(nums):
            return

        self.helper(nums,current+1,k,re,temp)
        self.helper(nums,current+1,k-1,re,temp+[nums[current]])

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        re=[]
        nums.sort()
        for i in xrange(len(nums)):
            self.helper(nums,0,i,re,[])
        re.append(nums)
        return re

    # 直接用循环的方法 每一次修改当前的result值
    def loopsubsets(self,nums):
        results=[[]]
        for i in xrange(len(nums)):
            for j in xrange(len(results)):
                new=results[j]+[nums[i]]
                results.append(new)
        return results

    #回溯的方法，不知道回溯的dfs的具体区别
    def backtracking(self,res,temp,nums,begin):
        res.append(temp)
        for i in xrange(begin,len(nums)):
            # if nums[i]==nums[i-1] and i>begin :
            #     print i,begin
            #     continue
            self.backtracking(res,temp+[nums[i]],nums,i+1)
        return res

solu = Solution()
print solu.backtracking([],[],[1,2,3],0)