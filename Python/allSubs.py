gList = []

def subStr(s, t):
    if(len(s) == 0):
        gList.append(t[:])
        return
    t.append(s[0])
    subStr(s[1:], t)
    t.pop()
    subStr(s[1:], t)
    return

s = "abc"
subStr(s, [])
print(gList)