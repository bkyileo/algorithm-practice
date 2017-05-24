#include<bits/stdc++.h>
using namespace std;
int findNthDigit(int n)
{
	//if(n<10)return n;
	int ct=1;
	bool f=true;
	while(f)
	{
		if(n>9*pow(10,ct-1)*ct)
		{
			n-=9*pow(10,ct-1)*ct;
			ct++;
		}
		else
		{
			f=false;
		}
	}
	int num=n/ct + pow(10,ct-1)-1;
	int mod=n%ct;
	if(mod!=0)num++;
	
	vector<int> tp;
	while(num)
	{
		tp.push_back(num%10);
		num/=10;
	}
	//for(auto i:tp)cout<<i<<" ";cout<<endl;
	if(mod==0)return tp[mod];
	else return tp[tp.size()-mod];
	
}
int native(int n) {
	/*
	1 - 9*1
	2 - 90*2
	3 - 900*3
	4 - 9000*4 
	*/
	vector<int> arr;
	int temp;
	for(int i=1;i<1000;++i)
	{
		temp=i;
		vector<int> tp;
		while(temp)
		{
			tp.push_back(temp%10);
			temp/=10;
		}
		for(int j=tp.size()-1;j>=0;--j)
		{
			arr.push_back(tp[j]);
		}
	}
	cout<<arr[n-3]<<" "<<arr[n-2]<<" "<<arr[n-1]<<" "<<arr[n]<<" "<<arr[n+1]<<endl;
	return arr[n-1];
}
    int thirdMax(vector<int>& nums) {
        vector<int> arr(3,INT_MIN);
        for(auto i:nums)
        {
            if(i>arr[0])
            {
                arr[2]=arr[1];
                arr[1]=arr[0];
                arr[0]=i;
            }
            else if(i<arr[0]&&i>arr[1])
            {
                arr[2]=arr[1];
                arr[1]=i;
            }
            else if(i<arr[1]&&i>arr[2])
            {
                arr[2]=i;
            }
        }
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        if(arr[2]==INT_MIN)
        {
            if(arr[1]==INT_MIN)
            {
                return arr[0];
            }
            return arr[1];
        }
        else
        {
            return arr[2];
        }
    }
    
	int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        int res=0;
        for(auto i:mp)
        {
            //cout<<i.first<<" "<<i.second<<endl;
            if(k>0 && mp.find(i.first+k)!=mp.end())res++;
            else if(k==0&&mp.find(i.first+k)!=mp.end()&&mp[i.first+k]>1)res++;
        }
        return res;
    }
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());
        map<int,int> ab;
        for(auto i:A)
        {
            for(auto j:B)
            {
                ab[i+j]++;
            }
        }
        int res=0;
        int tp;
        for(auto i:C)
        {
            for(auto j:D)
            {
                res+=ab[-i-j];
            }
        }
        return res;
    }
int main()
{
	//57-9=48
	//48/2=24
	//10+24=34
	//
	vector<int> arr={1,2,3,4,5,6};
	cout<<findPairs(arr,2);
	return 0;
} 
