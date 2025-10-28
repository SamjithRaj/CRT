gList = []

def subStr(s, t, i):
    if(i==len(s)):
        gList.append(t[:])
        return
    t.append(s[i])
    subStr(s, t, i+1)
    t.pop()
    subStr(s, t, i+1)
    return

s = "abc"
subStr(s, [], 0)
print(gList)