#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int counterOne = 0;
    int counterTwo = 0;
    int oldone;

    for (int i = 0; i < nums.size(); i++){
		oldone = counterOne;
        counterOne = (~counterOne)&nums[i]&(~counterTwo) | (~counterTwo)&(~nums[i])&counterOne;
        counterTwo = (~oldone)&(~nums[i])&counterTwo | (~counterTwo)&nums[i]&oldone;
//        counterOne = (~counterTwo) & (counterOne ^ nums[i]);
//        counterTwo = (~counterOne) & (counterTwo ^ nums[i]);
        
    }
    return counterOne;
} 

int main()
{
	vector<int> t;
	t.push_back(4);
	t.push_back(3);	
	t.push_back(3);
	t.push_back(3);
	t.push_back(1);
	t.push_back(4);
	t.push_back(4);
	t.push_back(2);
	t.push_back(2);
	t.push_back(2);
	cout<<"res : "<<singleNumber(t)<<endl;
//	int a=8;
//	int b=1;
//	cout<<(~a)<<endl; 
}



