n = int(input("Enter number: "))
digits = [int(d) for d in str(n)]
min_digit = min(digits)

new_base_digits = []
temp = n
while temp > 0:
    new_base_digits.append(temp % min_digit)
    temp //= min_digit
new_base_digits = new_base_digits[::-1] 
fact_sum = 0
for d in new_base_digits:
    f = 1
    for i in range(1, d+1):
        f *= i
    fact_sum += f

print(fact_sum)
