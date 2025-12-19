import math
n = int(input("Enter number: "))
cnt = int(math.log10(n) + 1)

temp = n
sum = 0

while temp > 0:
    val = temp % 10
    fact = 1
    temp_val = val
    while temp_val > 0:
        fact *= temp_val
        temp_val -= 1
    sum += fact
    temp //= 10

if n == sum:
    print("Strong number")
print(sum)