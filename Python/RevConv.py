import math
n = int(input("Enter number: "))
rem, quo, po, sum, comp, res = 0, 0, 0, 0, 0, 0
cnt = int(math.log10(n) + 1)
temp = n
ls = []
gb = 10  

while temp > 0:
    val = temp % 10
    ls.append(val)
    temp //= 10

ls.sort(reverse=True)
max = ls[0]
base = max

res = 0
po = 0
num = n
while num > 0:
    rem = num % base
    comp = rem * (gb ** po)   
    res += comp
    po += 1
    num //= base

print(res)

rev = 0
temp_res = res
while temp_res > 0:
    val = temp_res % 10
    rev = rev * 10 + val
    temp_res //= 10

print(rev)

po = 0
res = 0
num = rev
while num > 0:
    rem = num % 10
    comp = rem * (base ** po)   
    res += comp
    po += 1
    num //= 10

print(res)
