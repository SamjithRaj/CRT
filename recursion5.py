def rec(ls, x, pos):
    if pos == 0:
        ls.append(x)
        return
    temp = ls.pop()
    rec(ls, x, pos - 1)
    ls.append(temp)

lst = [1, 2, 4, 5]
rec(lst, 3, 2)
print(lst)
