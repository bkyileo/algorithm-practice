#include<bits/stdc++.h>
using namespace std;

/*
Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

bool isHappy(int n) {
	int sum=0;
	vector<int> temp;
	while(1)
	{
		sum=0;
		while(n)
		{
			sum += (n%10)*(n%10);
			n /= 10;
		}
		
		if (sum==1)
			return true;
		else{
			n=sum;
			for(int i=0;i<temp.size();++i)
			{
				if(temp[i]==sum)
					return false; 
			}
			temp.push_back(sum); 
			} 
	}        
}

int main()
{
	cout<<isHappy(19)<<endl;
	//19
	return 0; 
}



