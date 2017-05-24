__author__ = 'BK'
# coding=utf-8
'''
鉴于我市拥堵的交通状况，市政交管部门经过听证决定在道路两侧安置自动停车收费系统。
当车辆驶入车位，系统会通过配有的摄像头拍摄车辆画面，通过识别车牌上的数字、字母序列识别车牌，
通过连接车管所车辆信息数据库确认车辆，进行扣费。
斗智斗勇的好戏一般从此处展开…
一些车主通过在停车时遮挡车牌上的一个或多个数字、字母序列，来阻碍识别系统的识别工作，以此逃避停车费用的缴纳。
车主这简直是用轻轻的一挡搞出来一个世界难题有木有？！管理是一方面，技术解决才是王道啊。
这么难的项目不得不交给计蒜客实验室了。D 神负责识别颜色，E 神负责型号识别，可能的车牌范围就这么一点点的被缩小了。
作为实习生的蒜头也是任务艰巨，将已经存在车辆数据库中的可与当前已知信息相匹配的车牌信息筛选出来，这可是整个项目的第一步啊，重要性我就不多说了，加油吧。
输入
输入文件的第一行包含 9 个字符的字符序列代表识别的。
其中可识别的字符已由大写字母和数字显示，“*”表示因为遮挡而未被识别的字符。
输入文件的第二行包含一个整数 n (1 ≤ n ≤ 1000) —— 机动车数据库中的牌照信息的数量。
接下来 n 行，包含相应的牌照信息，每行一个。
牌照信息为长度为 9 的仅包含数字和大写字母的字符串。所有的牌照信息保证各不相同。
输出
输出文件的第一行为一个整数 k (0 ≤ k ≤ n) —— 符合给定要求的牌照数。
接下来的 k 行，输出所有可能的牌照信息。
样例1
输入：
A**1MP19*
4
A001MP199
E885EE098
A111MP199
KT7351TTB
输出：
2
A001MP199
A111MP199
'''

def get_parm():

    licen=raw_input()

    licen_list=[]

    num=input()

    for i in range(int(num)):
        licen_list.append(raw_input())

    return licen,licen_list

def get_ifpart(word1,word2,resultlist):

    count =len(word1)

    for i in range(count):
        if word1[i]==word2[i] or word1[i]=="*":
            count=count-1
        else:
            break

    if count==0:
        resultlist.append(word2)

    return resultlist

def get_answer(licen,licen_list):

    re=[]
    for i in range(len(licen_list)):
        re=get_ifpart(licen,licen_list[i],re)

    print len(re)

    for i in range(len(re)):
        print re[i]


if __name__=='__main__':

    licen,licen_list=get_parm()

    get_answer(licen,licen_list)



