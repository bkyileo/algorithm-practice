#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n = height.size();
        if (n < 1) return 0;

        int maxArea = height[0];

        for (int i = 1; i < n; i++)
        {
            if (height[i-1] > height[i])
            {
                int j = i -1;
                int curW = 0;
                while (j >= 0 && height[j] > height[i])
                {
                    curW++;
                    maxArea = max(maxArea, height[j] * curW);
                    height[j--] = height[i];
                }
            }
        }

        return maxArea;
    }
class Solution {
public:
    int maximalRectangle(vector< vector<char> >& matrix) {
    	
    	
		int rows = matrix.size();
		if (rows==0)
			return 0;
		int cols = matrix[0].size();
		
		vector< vector<int> > height(rows,vector<int>(cols,0));
		for (int i=0;i<cols;i++)
		{
			if (matrix[0][i]=='1')
				{height[0][i]=1;}
			cout<<height[0][i]<<" ";
		 } 
		cout<<endl;
		for (int i=1;i<rows;i++)
		{ 
			for (int j=0;j<cols;j++)
				{
				if (matrix[i][j]=='1')
					height[i][j]=height[i-1][j]+1;
					cout<<height[i][j]<<" ";
				}
			cout<<endl;
		} 
		int maxarea=0;
		int local;
		for (int i=0;i<rows;i++)
		{
			local = largestRectangleArea(height[i]);
			maxarea = maxarea>local ? maxarea:local ;
		}
		return maxarea;
    }

};

int main()
{
	vector<char> row1;
	vector<char> row2;
	vector<char> row3;
	vector<char> row4;
	
	row1.push_back('0');
	row1.push_back('0');
	row1.push_back('1');
	row1.push_back('0');
	
	row2.push_back('0');
	row2.push_back('1');
	row2.push_back('1');
	row2.push_back('0');
	
	row3.push_back('0');
	row3.push_back('0');
	row3.push_back('0');
	row3.push_back('0');
	
	row4.push_back('0');
	row4.push_back('0');
	row4.push_back('1');
	row4.push_back('1');
	
	vector< vector<char> > matrix;
	matrix.push_back(row1);
	matrix.push_back(row2);
	matrix.push_back(row3);
	matrix.push_back(row4);
	
	Solution solu;
	cout<<solu.maximalRectangle(matrix);
	
	return 0;
}
