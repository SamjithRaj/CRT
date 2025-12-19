def func(a, b):
    if b < a and (a^b > b-a):
        a = b+3
        a = b+3
        a = a+3
        return func(a, b+a)-a
    a = a+1+b
    return a-b

print(func(9,8))