ls = list(map(int, input().split()))
k = int(input("Enter size of the window: "))
temp = []
res = []
i = 0 
j = 0
while j < len(ls):
    while temp and temp[-1] < ls[j]:
        temp.pop()
    temp.append(ls[j])
    if j - i + 1 < k:
        j += 1
    else:
        res.append(temp[0])
        if ls[i] == temp[0]:
            temp.pop(0)
        i += 1
        j += 1

print(res)