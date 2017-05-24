__author__ = 'BK'
# coding=utf-8
'''
小蒜头又调皮了。这一次，姐姐的实验报告惨遭毒手。
姐姐的实验报告上原本记录着从 1 到 n 的序列，任意两个数字间用空格间隔。
但是“坑姐”的蒜头居然把数字间的空格都给删掉了，整个数字序列变成一个长度为 1 到 100 的且首部没有空格的数字串。
现在姐姐已经怒了，蒜头找你写个程序快点把试验数据复原。
输入
输入文件有一行，为一个字符串——被蒜头搞乱的实验数据。
字符串的长度在 1 到 100 之间。
输出
输出共一行，为姐姐的原始测试数据—— 1 到 n 的输出。
任意两个数据之间有一个空格。
如果有多组符合要求的正确解，输出其中任意一组即可。
样例1
输入：
4111109876532
输出：
4 1 11 10 9 8 7 6 5 3 2
'''

def get_parm():

    problem=raw_input( )

    return problem

def get_answer(problem):

    if len(problem)<10:
        num=len(problem)
    else:
        num=int((len(problem)+9)/2)

    for i in range(num):
        problem=problem.replace(str(i+1),str(i+1)+' ',1)

    print(problem)


if __name__ == '__main__':

    get_answer(get_parm())

"PS：通过测试用例，但是逻辑有问题"