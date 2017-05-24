__author__ = 'BK'
'''
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
'''
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        if len(strs)==0:
            return []

        d={}
        for s in strs:
            k="".join(sorted(s))
            if not d.has_key(k):
                d[k] = []
            d[k].append(s)
        result=[]
        for k,v in d.items():
            v.sort()
            result.append(v)
        return result

solu = Solution()
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
solu.groupAnagrams(strs)
