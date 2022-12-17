t = int(input())

def testcase():
    n = int(input())
    a = list(map(int, input().split()))
    res = 0
    small = min(a)
    big = max(a)
    a.remove(small)
    a.remove(big)

    a3 = sorted(a)
    a4 = a3[::-1]
    smallc = small
    bigc = big
    minmid = a3[0]
    maxmid = a3[-1]
    for i in range(len(a3)-1):
        if (a3[i] - smallc) <= (a3[i+1] - a3[i]) - (a3[i] - smallc):
            smallc = a3[i]
            minmid = a3[i+1]
    for i in range(len(a4)-1):
        if (bigc - a4[i]) <= (a4[i] - a4[i+1]) - (bigc - a4[i]):
            bigc = a4[i]
            maxmid = a4[i+1]

    if (minmid - smallc >= bigc - maxmid):
        res = (minmid-smallc) + (big - smallc)
    else:
        res = (bigc - maxmid) + (bigc - small)

    return res

for i in range(t):
    print(testcase())
