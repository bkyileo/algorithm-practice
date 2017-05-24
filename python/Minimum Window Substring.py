__author__ = 'BK'
'''
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

Subscribe to see which companies asked this question
'''
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        import sys
        D={}
        pos = 0;d=sys.maxint;count=len(t)
        start=0
        for i in t:
            if D.has_key(i):
                D[i] += 1
            else:
                D[i] = 1


        for i in xrange(len(s)):
            if D.has_key(s[i]):
                if D[s[i]]>0 :
                    count -= 1
                D[s[i]] -= 1

                while count==0:
                    if i-pos<d:
                        d=i-pos
                        start=pos

                    if D.has_key(s[pos]):
                        D[s[pos]] += 1

                        if D[s[pos]]>0:
                            count += 1

                    pos += 1

        if d<sys.maxint:
            return s[start:start+d+1]
        else:
            return ''

solu = Solution()
S = "ADOBECODEBANC"
T = "ABC"
print solu.minWindow(S,T)