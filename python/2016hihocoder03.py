# coding=utf-8
__author__ = 'BK'
'''
描述
小Ho很喜欢在课间去小卖部买零食。然而不幸的是，这个学期他又有在一教的课，而一教的小卖部姐姐以冷若冰霜著称。第一次去一教小卖部买零食的时候，小Ho由于不懂事买了好一大堆东西，被小卖部姐姐给了一个“冷若冰霜”的眼神，食欲都下降了很多。

从那以后，小Ho就学乖了，去小卖部买东西只敢同时买3包以内的零食，并且价格加起来必须是5的整数倍，方便小卖部姐姐算价格。

但是小Ho不擅长计算，所以他把小卖部里所有零食的价格以及他对这个零食的渴望度都告诉了你，希望你能够帮他计算出在不惹恼小卖部姐姐的前提下，能够买到零食的渴望度之和最高是多少？

输入
每个输入文件包含多组测试数据，在每个输入文件的第一行为一个整数Q，表示测试数据的组数。

每组测试数据的第一行为一个正整数N，表示小卖部中零食的数量。

接下来的N行，每行为一个正实数A和一个正整数B，表示这种零食的价格和小Ho对其的渴望度。

一种零食仅有一包。

对于100%的数据，满足1 <= Q <= 10，1<=N<=50，0<A<=10，1<=B<=100。

对于100%的数据，满足A的小数部分仅可能为0.5或0。

输出
对于每组测试数据，输出一个整数Ans，表示小Ho可以获得最大的渴望度之和。
样例输入
1
4
0.5 6
4.5 7
5.0 4
2.0 9
样例输出
17

3个以内 5的倍数
'''

def func():
    n=int(raw_input())
    for i in xrange(n):
        m=int(raw_input())
        prices=[]
        wants=[]
        for j in xrange(m):
            line = raw_input().split()
            prices.append(float(line[0]))
            wants.append(int(line[1]))

        maxWant=0
        # case 1
        for i in xrange(m):
            if prices[i]%5==0:
                maxWant=max(maxWant,wants[i])
        # case 2
        for i in xrange(m):
            for j in xrange(i+1,m):
                if (prices[i]+prices[j])%5==0:
                    maxWant=max(maxWant,wants[i]+wants[j])
        # case 3
        for i in xrange(m):
            for j in xrange(i+1,m):
                for k in xrange(j+1,m):
                    if (prices[i]+prices[j]+prices[k])%5==0:
                        maxWant=max(maxWant,wants[i]+wants[j]+wants[k])

        print maxWant

func()