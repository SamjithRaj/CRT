c = 0
def transfer(n, source, destination, helper):
    global c
    if n == 0:
        return
    transfer(n-1, source, helper, destination)
    print(f"Move disk {n} from {source} to {destination}")
    c+=1
    transfer(n-1, helper, destination, source)
    return


n = int(input())
transfer(n, 'Src', 'Dst', 'Hlp')
print(f"Total moves: {c}")
