__author__ = 'BK'

M,N=raw_input().split(' ')


Cache=[]
for i in range(int(M)):
    web=raw_input()

    if web in Cache:
        Cache.remove(web)
        Cache.append(web)
        print 'Cache'

    elif len(Cache)<int(N):
        Cache.append(web)
        print 'Internet'

    else:
        Cache.remove(Cache[0])
        Cache.append(web)
        print 'Internet'



