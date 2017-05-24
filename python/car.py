__author__ = 'BK'
# coding=utf-8
'''
n 辆赛车在一条长长的直道上展开同台竞技。每辆赛车的速度都为 1m/s，整条赛道在每一米都有坐标标记。
在比赛的赛车中，赛车 i 从 0 秒开始由 ai 向 bi 移动。到达 bi 之后转而返回由 bi 向 ai 移动。循环往复。
问题 j 是：在 tj 时刻，在 xi 到 yi 之间共有几辆赛车？

输入
输入的第一行包含两个数字 n 和 m（1 ≤ n, m ≤ 1000），分别代表正在比赛的赛车数量和问题数。
接下来的 n 行中，每行包含 2 个整数 ai、bi（0 ≤ ai, bi ≤ 109, ai != bi），分别代表赛车 i 的起点和终点。
再接下来的 m 行中，每行包含 3 个整数 xj，yj，tj（0 ≤ xj ≤ yj ≤ 109, 0 ≤ tj ≤ 109)，分别代表问题 j 的左右坐标边界和询问的时间。
输出
输出共有 m 行，每行各有一个整数，分别代表对应的 m 个问题的答案。
样例1
输入：
5 5
0 1
0 2
2 3
3 5
4 5
0 5 0
0 1 2
0 2 1
2 5 2
2 5 3
输出：
5
1
2
4
3
'''

def get_parm():

    n,m=raw_input( ).split( )

    road=[]

    for i in range(int(n)):
        a,b=raw_input( ).split( )
        road.append((int(a),int(b)))

    problem=[]

    for i in range(int(m)):
        x,y,t=raw_input( ).split( )
        problem.append((int(x),int(y),int(t)))

    return int(m),road,problem

def where(time,road):

    start=road[0]
    end=road[1]

    cicle=time/(end-start)
    els=time%(end-start)

    if cicle%2==0:
        return start+els
    else:
        return end-els

def get_answer(m,road,problem):

    for i in range(m):

        start=problem[i][0]
        end=problem[i][1]
        time=problem[i][2]

        count=0

        for t in range(len(road)):
            if where(time,road[t])<=end and where(time,road[t])>=start:
                count=count+1
        print count


if __name__ == '__main__':
    m,road,problem=get_parm()
    get_answer(m,road,problem)
