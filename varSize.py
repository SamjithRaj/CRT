ls = list(map(int, input().split()))

sum = int(input("Enter the sum: "))
i = j = 0
current = 0
count = 0
while j < len(ls):
    current += ls[j]
    while current > sum and i <= j:
        current -= ls[i]
        i += 1
    if current == sum:
        count += 1
        temp = j + 1
        while temp < len(ls) and ls[temp] == 0:
            count += 1
            temp += 1
        current -= ls[i]
        i += 1
    j += 1
print(count)    
