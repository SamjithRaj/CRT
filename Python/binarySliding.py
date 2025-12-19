ls = list(map(int, input().split()))
k = int(input("Enter size of the window: "))

dict = {}
dict[0] = 0
dict[1] = 0

i = 0
j = 0

max = 0
for i in range(len(ls)):
    if ls[i] == 1:
        dict[1] += 1
    else:
        if dict[0] < k:
            dict[0] += 1
    max += 1

print(dict)