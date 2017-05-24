//code chef Chef and Amazingness of Numbers

/*
amazingness(a)
{
    set s;
    int ans = 0;
    for ( int i = 0; i < a.length(); i++ ) {
         int val = 0;
         for ( int j = i; j < a.length(); j++ ) {
            val ^= a[j];  
            // a[j] denotes digit at j-th (0-based indexing) position of n counting 
 from most signficant digit (left to right).
            if (val not present in set s before) {
                 ans += val;
                 add val to set s
            }
         }
   }
   return ans;
}
*/

#include<bits/stdc++.h>
using namespace std;
#define long long ll

int amazing(vector<int> a)
{
	set<int> s;
	int ans=0;
	for(int i=0;i<a.size();i++)
	{
		int val=0;
		for(int j=i;j<a.size();j++)
		{
			val^=a[j];
			cout<<a[j]<<" "<<val<<endl;
		}
		
		if (s.find(val)==s.end())
		{
			ans+=val;
			s.insert(val);
		}
	}
	return ans;
}

int main()
{
	vector<int> a{1,2};

	
	cout<<amazing(a)<<endl;

	return 0;
}
