ls = []
ls = list(map(int, input().split()))
k = int(input("Enter size of the window: "))
sum = 0

for i in range(0, k):
    sum += ls[i]
print(sum, end=" ")

for i in range(len(ls) - k):
    sum = sum - ls[i] + ls[i + k]
    print(sum, end=" ")
print()

    