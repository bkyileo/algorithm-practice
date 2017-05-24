__author__ = 'BK'
'''
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
'''
def diff(s1,s2):
    count = 0
    for i in xrange(len(s1)):
        if s1[i] != s2[i]:
            count += 1
    if count==1:
        return True
    return False

def bfs(currWord,endWord,currStep,res,wordList,addlist):
    if diff(currWord,endWord):
        #print addlist
        print res,currStep+1
        res = min(res,currStep+1)
        print res
        return

    for i in wordList:
        if diff(currWord,i) and (i not in addlist):
            bfs(i,endWord,currStep+1,res,wordList,addlist+[i])


class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: Set[str]
        :rtype: int
        """
        import sys
        res = sys.maxint
        bfs(beginWord,endWord,0,res,wordList,[])
        if len(res)==0:
            return 0
        return min(res)+1

solu=Solution()
# beginWord = "hit"
# endWord = "cog"
# wordList = ["hot","dot","dog","lot","log"]

beginWord = "qa"
endWord = "sq"
wordList = ["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]
print len(wordList)
print solu.ladderLength(beginWord,endWord,wordList)