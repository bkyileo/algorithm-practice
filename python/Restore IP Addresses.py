__author__ = 'BK'
'''
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Subscribe to see which companies asked this question
'''
class Solution(object):
    def helper(self,res,s,left):

        if s.split('.')[-1]=='':
            return

        if left==0:
            check=s.split('.')
            if int(check[-1])<256 and ((int(check[-1])>99 and len(check[-1])==3) or(int(check[-1])>9 and len(check[-1])==2) or len(check[-1])==1):
                if ((int(check[0])>99 and len(check[0])==3) or(int(check[0])>9 and len(check[0])==2) or len(check[0])==1)and((int(check[1])>99 and len(check[1])==3) or(int(check[1])>9 and len(check[1])==2) or len(check[1])==1)and((int(check[2])>99 and len(check[2])==3) or(int(check[2])>9 and len(check[2])==2) or len(check[2])==1) :
                    res.append(s)


        self.helper(res,s[0:s.rfind('.')+2]+'.'+s[s.rfind('.')+2:],left-1)
        self.helper(res,s[0:s.rfind('.')+3]+'.'+s[s.rfind('.')+3:],left-1)
        if int(s[s.rfind('.')+1:s.rfind('.')+4])<256:
            self.helper(res,s[0:s.rfind('.')+4]+'.'+s[s.rfind('.')+4:],left-1)




    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if len(s)<4 or len(s)>12:
            return []
        res=[]
        self.helper(res,s,3)
        return res

solu = Solution()
res=[]
# s="25525511135"
#s="010010"
s="44610202"
print solu.restoreIpAddresses(s)

#print s.split('.')
# print s[0:5]+'.'+s[5:]
#print int('01')