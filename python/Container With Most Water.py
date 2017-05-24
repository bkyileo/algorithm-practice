__author__ = 'BK'
'''
Given n non-negative integers a1, a2, ..., an, where each
represents a point at coordinate (i, ai). n vertical lines are drawn
such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container,
such that the container contains the most water.

Note: You may not slant the container.

Subscribe to see which companies asked this question
'''

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left=0
        right=len(height)-1

        area = min(height[left],height[right])*(right-left)
        if height[right]>height[left]:
            pendulum = 0
        else:
            pendulum=1

        while right>left:
            print left,right,area
            if pendulum%2==0:

                if min(height[left+1],height[right])*(right-left-1)>area:
                    area=min(height[left+1],height[right])*(right-left-1)

                if height[left+1]>=height[right]:
                    pendulum = pendulum+1

                left = left+1
                continue

            else:

                if min(height[left],height[right-1])*(right-left-1)>area:
                    area=min(height[left],height[right-1])*(right-left-1)

                if height[right-1]>=height[left]:
                    pendulum = pendulum+1

                right = right-1
                continue
        return area

solu=Solution()
print solu.maxArea([2,6,5,1])