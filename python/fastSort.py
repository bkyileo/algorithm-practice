__author__ = 'BK'

def quickSort(L, low, high):
    i = low
    j = high
    if i >= j:
        return L
    key = L[i]
    while i < j:
        while i < j and L[j] >= key:
            print '>'
            j = j-1
        #print j
        L[i] = L[j]
        print L
        while i < j and L[i] <= key:
            i = i+1
            print '<'
        #print i
        L[j] = L[i]
        print L
    L[i] = key
    print 'L'+str(L)
    quickSort(L, low, i-1)
    quickSort(L, j+1, high)
    return L

a=[2,1,3,1,2,3,1,2,3]

print quickSort(a,0,len(a)-1)