a = 5
b = 5
def f(a,b):
    if(a < b):
        return f(b, a)
    elif b!=0:
        return a*f(a, b-1)
    else:
        return 1


    return f(a, b)      