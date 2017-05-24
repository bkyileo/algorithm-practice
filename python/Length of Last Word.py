__author__ = 'BK'
'''
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

Subscribe to see which companies asked this question
'''
def solution(s):
    s=s.split()
    if s==[]:return 0
    return len(s[-1])

print solution('')
