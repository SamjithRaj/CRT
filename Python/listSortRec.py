def lsSort(l):
    if len(l) == 0:
        return
    t = l.pop()
    lsSort(l)
    insert(l, t)
    return

def insert(l,e):
    if len(l) == 0 or l[-1] <= e:
        l.append(e)
        return
    t = l.pop()
    insert(l, e)
    l.append(t)
    return

l = [5, 3, 8, 6, 2, 7]
lsSort(l)
print(l)