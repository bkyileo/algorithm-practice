#include<bits/stdc++.h>
using namespace std;
int numberOfBoomerangs(vector<pair<int, int>>& points) {
	int res=0;
	int dis;
	map<int,int> mp;
	for(int i=0;i<points.size();++i)
	{
		mp.clear();
		for(int j=0;j<points.size();++j)
		{
			if(i!=j)
			{
				dis=
				(points[i].first-points[j].first)*(points[i].first-points[j].first)+
				(points[i].second-points[j].second)*(points[i].second-points[j].second);
				mp[dis]++;
			}
		}
		for(auto i:mp)
		{
			res+=i.second*(i.second-1);
		}
	}
	return res;
}

string addStrings(string num1, string num2) {
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());
	string res="";
	int c=0;
	int a,b,d;
	for(int i=0;i<max(num1.length(),num2.length());++i)
	{
		a = i<num1.length() ? num1[i]-'0':0;
		b = i<num2.length() ? num2[i]-'0':0;
		d=a+b+c;
		if(d>9)c=1;
		else c=0;
		res=(char)( d%10 + '0' ) + res;
	}
	if(c)res='1'+ res;
	return res;
}

string toHex(int num) {
	if(!num)return "0";
	string res="";
	int count=0;
	while(num&&count<8)
	{
		//cout<<num<<endl;
		int curr=num&15;
		if(curr>9)
		res+='a'+(curr-10);
		else
		res+=curr+'0';
		
		num=num>>4;
		count++;
	}
	reverse(res.begin(),res.end());
	return res;
}

vector<int> findAnagrams(string s, string p) {
	vector<int> mp(26,0);
    for(auto i:p)mp[i-'a']++;
    vector<int> res;
    vector<int> tp=mp;
    for(int j=0;j<s.length();++j)
    {
        tp[s[j]-'a']--;
        if(j>=p.length())
        {
        	tp[s[j-p.length()]-'a']++;
		}
        bool f=true;
        for(int i=0;i<26;++i)
        {
            if(tp[i]==0)continue;
            if(tp[i]>0){f=false;break;}
            if(tp[i]<0){f=false;break;}
        }
        if(f)
        {
            res.push_back(j-p.length()+1);
        }
    }
    //for(auto i:res)cout<<i<<" ";cout<<endl;
    return res;
}
int main()
{
	findAnagrams("cbaebabacd","abc");
	return 0;
} 
