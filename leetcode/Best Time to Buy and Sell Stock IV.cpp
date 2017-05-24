#include<bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
        vector<int> buys(k,INT_MIN);
        vector<int> sells(k+1,0);
        
        for(int i=0;i<prices.size();++i)
        {
        	for(int j=k;j>-1;--j)
        	{
        		if(j!=0)
        		{
        			sells[j]=max(sells[j],buys[j-1]+buys[j]);
        			buys[j]=max(buys[j],sells[j-1]-prices[i]);
				}
				else
				{
					sells[1] = max(sells[1], res[0] + prices[i]);  // Transaction 1: sell
            		buys[0] = max(buys[0], -prices[i]);   
				}

			}
		}
		return sells[k-1];
} 
