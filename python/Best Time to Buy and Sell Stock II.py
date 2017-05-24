# coding=utf-8
__author__ = 'BK'
'''
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most two transaction
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
'''
def getAnswer(prices):
    days=len(prices)
    profit=0
    min_price=prices[0]

    for i in xrange(1,days):

        profit=max(profit,prices[i]-min_price)
        min_price=min(min_price,prices[i])

    return profit,min_price

class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        days=len(prices)
        if days==0:
            return 0
        profit=0
        min_price=prices[0]

        for i in xrange(1,days):
            if prices[i]-min_price>profit:
                profit=prices[i]-min_price
                a=prices[i]
            min_price=min(min_price,prices[i])

        if profit==0:
            return 0

        print a,a-profit
        prices.remove(a)
        prices.remove(a-profit)
        print prices

        days=len(prices)
        if days==0:
            return profit

        profit2=0
        min_price=prices[0]

        for i in xrange(1,days):

            profit2=max(profit2,prices[i]-min_price)
            min_price=min(min_price,prices[i])
        return profit+profit2

if __name__=='__main__':
    test=[6,1,3,2,4,7]

    solu=Solution()
    #print solu.maxProfit(test)
    print solu.maxProfit(test)
