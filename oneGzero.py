gList = []

def Number(one, zero, n, t=""):
    if n == 0:
        if t.count("1") > t.count("0"):
            gList.append(t)
            return
    
    if one > 0:
        Number(one - 1, zero, n - 1, t + "1")
    
    if zero > 0:
        Number(one, zero - 1, n - 1, t + "0")
    
n = 3
Number(3,3,n)
print(gList)