def func(l, e):
    if(len(l) == 0):
        l.append(e)
        return 
    t = l.pop()
    func(l, e)
    l.append(t)
    return 


l = [5, 7, 9, 6]
e = 11
func(l, e)
print(l)