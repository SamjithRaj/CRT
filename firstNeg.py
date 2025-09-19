ls = list(map(int, input().split()))
k = int(input("Enter size of the window: "))
temp = []
res = []
i = 0 
j = 0
while j < len(ls):
    if ls[j] < 0:
        temp.append(j)
    if j - i + 1 < k:
        j += 1
    else:
        if temp and temp[0] >= i:
            res.append(ls[temp[0]])
        else:
            res.append(0)
        if temp and temp[0] == i:
            temp.pop(0)
        i += 1
        j += 1

print(res)