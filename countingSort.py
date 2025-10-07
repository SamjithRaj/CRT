ls = list(map(int, input("Enter the elements: ").split()))
cnt = [0] * (max(ls) + 1)

for i in range(len(ls)):
    cnt[ls[i]] += 1

for i in range(max(ls)+1):
    while cnt[i] > 0:
        print(i, end=" ")
        cnt[i] -= 1
