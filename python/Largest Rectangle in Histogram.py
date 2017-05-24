__author__ = 'BK'
'''
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

Subscribe to see which companies asked this question
'''

class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type height: List[int]
        :rtype: int
        """
        heights.append(0)
        stack = [-1]
        ans = 0
        for i in xrange(len(heights)):
            while heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]
                w = i - stack[-1] -1
                print h,w,ans,i,stack
                ans = max(ans, h * w)
            stack.append(i)
        heights.pop()
        print ans


solu = Solution()
solu.largestRectangleArea([2,2,1,1,1,1])