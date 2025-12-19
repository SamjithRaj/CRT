n = int(input("Enter number: "))
temp = n
result = []

while temp > 10:
    pair = temp % 100
    rev_pair = (pair % 10) * 10 + (pair // 10)
    result.append(rev_pair)
    temp //= 10
    
print("Reversed pairs:", result)
print("Sum:", sum(result))


-a = 10
print(-a)