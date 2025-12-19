def rec(ls, pos):
    if pos == 1:
        ls.pop()
        return
    temp = ls.pop()
    rec(ls, pos - 1)
    ls.append(temp)

ls = [1, 2, 4, 5]
rec(ls, 2)
print(ls)
