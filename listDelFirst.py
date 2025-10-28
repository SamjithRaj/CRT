def delFirst(l):
    if len(l) == 1:
        l.pop()
        return
    t = l.pop(-1)
    delFirst(l)
    l.append(t)
    return

l = [5, 7, 9, 6, 7, 3, 7]
delFirst(l)
print(l)  