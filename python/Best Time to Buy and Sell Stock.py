# coding=utf-8
__author__ = 'BK'
'''
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
'''

class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        days=len(prices)
        profit=0
        min_price=prices[0]

        for i in xrange(1,days):

            profit=max(profit,prices[i]-min_price)
            min_price=min(min_price,prices[i])

        return profit

if __name__=='__main__':
    test=[2,1,2,1,0,1,2]

    solu=Solution()
    #print solu.maxProfit(test)
    print -4%3