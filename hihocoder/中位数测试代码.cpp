#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(),nums.end());
    while(--k)
    {
        pop_heap (nums.begin(),nums.end()); nums.pop_back();
    }
    return nums.front();
}
int main()
{
    vector<int> arr{1,5,2,4,3};
    cout<<selection_algorithm(arr,1,5,5);
}
