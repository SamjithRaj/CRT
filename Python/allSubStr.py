gList = []

def subStr(s, t):
    if(len(s) == 0):
        gList.append(t)
        return
    op1 = t+s[0]
    op2 = t
    subStr(s[1:], op1)
    subStr(s[1:], op2)
    return

s = "abc"
subStr(s, "")
print(gList)