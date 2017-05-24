__author__ = 'BK'
'''
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
'''

def letterCombinations(digits):
    def recur(digits):
        if not digits or len(digits) == 0:
            return []
        dic = {'1':['*'],
               '2':['a','b','c'],
               '3':['d','e','f'],
               '4':['g','h','i'],
               '5':['j','k','l'],
               '6':['m','n','o'],
               '7':['p','q','r','s'],
               '8':['t','u','v'],
               '9':['w','x','y','z'],
               '0':[' ']}

        if len(digits) == 1:
            return dic[digits]

        for s in digits:
            return [i + j for i in dic[digits[0]] for j in recur(digits[1:])]
    return recur(digits)


re=[]
def dfs(re,s,digits):

    dic = { '1':['*'],
            '2':['a','b','c'],
            '3':['d','e','f'],
            '4':['g','h','i'],
            '5':['j','k','l'],
            '6':['m','n','o'],
            '7':['p','q','r','s'],
            '8':['t','u','v'],
            '9':['w','x','y','z'],
            '0':[' ']}

    if len(digits)==0:
        re.append(s)
        return

    for i in xrange(len(dic[digits[0]])):
        dfs(re,s+dic[digits[0]][i],digits[1:])


print dfs(re,'','23')
print re