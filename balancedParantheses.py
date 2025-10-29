gList = []

def balanced(open, close, t=""):
    if open == 0 and close == 0:
        gList.append(t)
        return
    
    if open > 0:
        balanced(open - 1, close, t + "(")
    
    if close > open:
        balanced(open, close - 1, t + ")")

n = 3
balanced(n, n)
print(gList)