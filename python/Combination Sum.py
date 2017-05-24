# coding=utf-8
__author__ = 'BK'
'''
Given a set of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
Subscribe to see which companies asked this question

回溯算法的步骤 1.0
func:
    if step(这一步合法):
        if func(递归下一步也合法)：
            return true
        else：
            回溯
    return
'''

class Solution(object):

    def helper(self,candidates,target,re):
        '''
        堆栈分析：
        candidates=[2,3,5,7]，target=7,re=[]
        candidates=[2,3,5,7]，target=5,re=[2]
        candidates=[2,3,5,7]，target=3,re=[2,2]
        candidates=[2,3,5,7]，target=1,re=[2,2,2]
        target-2<0 return false ——> pop 实现回溯

        candidates=[2,3,5,7]，target=3,re=[2,2]
        for i in candidates: 走循环第二个数字
        target=0 return
        递归回来主函数return 不会走之后的for步骤
        '''
        if target== 0:
            return True

        for i in candidates:
            if target-i >= 0 :
                re += [i]
                if self.helper(candidates,target-i,re):
                    return True
                else:
                    re.pop()

        return False

    def helper2(self,candidates,target,re,temp):
        '''
        堆栈分析：
        1 candidates=[2,3,5,7]，target=7,re=[],temp=[]
        2 candidates=[2,3,5,7]，target=5,re=[],temp=[2]
        3 candidates=[2,3,5,7]，target=3,re=[],temp=[2,2]
        4 candidates=[2,3,5,7]，target=1,re=[],temp=[2,2,2] 这种情况下 target<0 直接 return
        再走第三步的 for循环 第二个数字

        candidates=[2,3,5,7]，target=3,re=[2,2]
        for i in candidates: 走循环第二个数字 这个时候 temp 也会进行回溯
        target=0 return
        '''
        print candidates,target,re,temp
        if target== 0:
            re+=[temp]
            return
        for i in xrange(len(candidates)):
            if candidates[i]<=target:
                self.helper2(candidates[i:],target-candidates[i],re,temp+[candidates[i]])

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        re=[]
        temp=[]
        candidates=sorted(set(candidates))
        self.helper2(candidates,target,re,temp)
        return re



solu = Solution()
candidates = [2,3,5,7]
target = 7
print solu.combinationSum(candidates,target)

