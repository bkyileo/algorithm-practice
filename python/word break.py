# coding=utf-8
__author__ = 'BK'
'''
Given a string s and a dictionary of words dict,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
'''

class Solution:
    # @param s, a string
    # @param wordDict, a set<string>
    # @return a boolean
    def wordBreak(self, s, wordDict):

        size=len(s)
        res=[False]*size

        for i in range(size):
            for j in range(i+1,size+1):
                # print s[i:j]
                if s[i:j] not in wordDict:
                    continue
                if i==0 or (i>0 and res[i-1]):
                    res[j-1]=True
        #print res
        return res[size-1]


if __name__=='__main__':
    solu = Solution()

    s = "leetcode"
    dict = ["leet", "code"]
    print solu.wordBreak(s,dict)