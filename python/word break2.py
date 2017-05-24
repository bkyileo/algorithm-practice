__author__ = 'BK'
'''
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

Subscribe to see which companies asked this question
'''

class Solution(object):
    def helper(self,res,temp,s,wordDict,visit):
        if s=='':
            res.append(temp[1:])
        for i in wordDict:
            if i==s[:len(i)] and i not in visit:
                self.helper(res,temp+' '+i,s[len(i):],wordDict,visit+[i])

    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: List[str]
        """
        res=[]
        self.helper(res,'',s,wordDict,[])
        return res

solu = Solution()
s = "catsanddog"

dict = ["cat", "cats", "and", "sand", "dog"]
print solu.wordBreak(s,dict)
# ["cats and dog", "cat sand dog"].
