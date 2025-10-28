def insert(l,e):
    if len(l) == 0 or l[-1] < e:
        l.append(e)
        return
    t = l.pop()
    insert(l, e)
    l.append(t)
    return

l = [2,3,4,5]
e = 1
insert(l, e)
print(l)