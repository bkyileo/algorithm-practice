__author__ = 'BK'
'''
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
'''
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        temp=''
        for i in digits:
            temp += str(i)
        temp = int(temp)+1
        res=[]
        while temp>0:
            res.append(temp%10)
            temp=temp/10
        res.reverse()
        return res

solu = Solution()
print solu.plusOne([1,2,3])