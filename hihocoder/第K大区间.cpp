#include<bits/stdc++.h>
using namespace std;
int pKLargest(vector<int> &nums, int start, int end, int k)
{
    int pivot = nums[end];
    int left = start;
    int right = end;
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (nums[j] <= pivot)
        {
            i++;
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
    }
    i++;
    int temp = nums[end];
    nums[end] = nums[i];
    nums[i] = temp;
    if (end - i + 1 == k)
        return nums[i];
    else if (end - i + 1 > k)
        return pKLargest(nums, i+1, end, k);
    else return pKLargest(nums, start, i-1, k - (end - i + 1));
}
int findKthLargest(vector<int> temp, int k,vector<int>::iterator left,int len) {
    vector<int> nums(left,left+len);
    return pKLargest(nums, 0, nums.size() - 1, k);
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    vector<int> overall;
    while(n--)
    {
        int curr;
        cin>>curr;
        arr.push_back(curr);
        overall.push_back(curr);
    }
    for(int i=3;i<=arr.size();i=i+2)
    {
        for(vector<int>::iterator j=arr.begin();j!=arr.end()-i+1;++j)
        {
            overall.push_back(findKthLargest(arr,i/2+1,j,i));
        }
    }
    cout<<findKthLargest(overall,k,overall.begin(),overall.size())<<endl;
}
