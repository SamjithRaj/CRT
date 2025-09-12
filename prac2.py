n = int(input("Enter number: "))
n_str = str(n)
digits = [int(d) for d in n_str]

max_digit = max(digits)
min_digit = min(digits)

fact_sum = 1
for i in range(1, max_digit + 1):
    fact_sum *= i
max_fact = fact_sum

fact_sum = 1
for i in range(1, min_digit + 1):
    fact_sum *= i
min_fact = fact_sum

print(max_fact + min_fact)
