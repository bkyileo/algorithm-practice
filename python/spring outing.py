# coding=utf-8
__author__ = 'BK'
'''
时间限制:20000ms
单点时限:1000ms
内存限制:256MB
描述
You class are planning for a spring outing. N people are voting for a destination out of K candidate places.

The voting progress is below:

First the class vote for the first candidate place. If more than half of the class agreed on the place, the place is selected. The voting ends.

Otherwise they vote for the second candidate place. If more than half of the class agreed on the place, the place is selected. The voting ends.

Otherwise they vote for the third candidate place in the same way and go on.

If no place is selected at last there will be no spring outing and everybody stays at home.

Before the voting, the Chief Entertainment Officer did a survey, found out every one's preference which can be represented as a permutation of 0, 1, ... K. (0 is for staying at home.) For example, when K=3, preference "1, 0, 2, 3" means that the first place is his first choice, staying at home is the second choice, the second place is the third choice and the third place is the last choice.

The Chief Entertainment Officer sends the survey results to the class. So everybody knows the others' preferences. Everybody wants his more prefered place to be selected. And they are very smart, they always choose the optimal strategy in the voting progress to achieve his goal.

Can you predict which place will be selected?

输入
The first line contains two integers, N and K, the number of people in your class and the number of candidate places.

The next N lines each contain a permutation of 0~K, representing someone's preference.

For 40% of the data, 1 <= N, K <= 10

For 100% of the data, 1 <= N, K <= 1000

输出
Output the selected place. Or "otaku" without quotes if no place is selected.
样例输入
2 2
1 0 2
2 1 0
样例输出
1
'''


def solution():

    line=raw_input()
    people,places = int(line.split()[0]),int(line.split()[1])
    data=[[0 for i in xrange(places+1)]for j in xrange(people)]

    for i in xrange(people):
        vote=raw_input().split()
        for j in xrange(len(vote)):
            data[i][int(vote[j])]=j

    res=[0]*(places+1)

    for i in xrange(places,0,-1):
        votes = 0
        for j in data:
            if j[i]<j[res[i]]:
                votes += 1

        if votes > people/2:
            res[i-1] = i
        else:
            res[i-1] = res[i]

    if res[0] == 0:
        print 'otaku'
    else:
        print res[0]

solution()