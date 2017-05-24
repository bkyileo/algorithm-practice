# coding=utf-8
__author__ = 'BK'
'''
Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
Subscribe to see which companies asked this question
'''

class Solution(object):

    def helper(self,cand,target,re,temp):

        if target==0:
            if temp not in re:
                re.append(temp)
            return

        for i,num in enumerate(cand):
            if num <= target:
                self.helper(cand[i+1:],target-num,re,temp+[num])


    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        re=[]
        temp=[]
        self.helper(candidates,target,re,temp)
        return re

cand = [10,1,2,7,6,1,5]
target = 8
solu=Solution()
print solu.combinationSum2(cand,target)