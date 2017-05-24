__author__ = 'BK'
'''
Given a sorted array, remove the duplicates in place such that each
element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums
being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question
'''

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<2:
            return len(nums)

        slow = 0
        fast = 1

        while fast < len(nums):
            print fast,slow,nums

            if nums[slow] != nums[fast] :
                print 'go'
                slow += 1
                nums[slow]=nums[fast]

            fast += 1


        return slow+1

'''
public int removeDuplicates(int[] nums) {
        int index= 0;
        for(int i =1 ;i <nums.length;i++){
            if(nums[i]!=nums[index]&&i!=++index){
                nums[index]=nums[i];
            }
        }
        return index+1;
    }
'''

solu=Solution()
a=[1,1,2,2,2,3,4,5]
print solu.removeDuplicates(a)
print a
