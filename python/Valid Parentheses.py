__author__ = 'BK'
'''
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}"
are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question
'''

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        # D={
        #     '(':[0,1],
        #     ')':[0,-1],
        #     '{':[1,1],
        #     '}':[1,-1],
        #     '[':[2,1],
        #     ']':[2,-1]
        # }
        #
        # re=[0,0,0]
        #
        # for i in s:
        #     re[D[s][0]] += D[s][1]

        #if len(s) == 0:
        #    return True
        #elif s[0:2]=='[]' or s[0:2]=='()' or s[0:2]=='{}':
        #    return self.isValid(s[2:])
        #return False

        if len(s)%2==1:
            return False

        re=[]
        for i in s:
            if i == '{' or i=='(' or i=='[':
                re.append(i)
            elif len(re) ==0:
                return False
            elif i==')' and re[-1]=='(':
                re.pop()
            elif i==']' and re[-1]=='[':
                re.pop()
            elif i=='}' and re[-1]=='{':
                re.pop()
            else:
                return False

        if len(re)==0:
            return True
        else:
            return False

solu = Solution()
print solu.isValid('()[]{}')
