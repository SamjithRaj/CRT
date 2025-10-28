gList = []

def index(s, t, i=0):
    if(i == len(s)):
        gList.append(t)
        return
    op1 = t+s[i]+'-'
    op2 = t+s[i]
    index(s, op1, i+1)
    index(s, op2, i+1)
    return

s = 'abc'
t = ''
index(s,t)
print(gList)