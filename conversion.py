import math
n = int(input("Enter number: "))
cnt = int(math.log10(n) + 1)
rem, quo, po, sum, comp, res = 0, 0, 0, 0, 0, 0
g = int(input("Given base: "))
d = int(input("Desired base: "))

temp = n
boo = False

while temp > 0:
    val = temp % 10
    if val >= g:
        boo = True
        break
    temp //= 10

if boo == False:
    temp = n
    while temp > 0:
        rem = temp % 10
        comp = rem * (g ** po)
        sum += comp
        po += 1
        temp //= 10

    
    if d == 10:
        print(sum)
    else:
        temp = sum
        res_str = ""
        if temp == 0:
            res_str = "0"
        while temp > 0:
            rem = temp % d
            res_str = str(rem) + res_str
            temp //= d
        print(res_str)

else:
    print(f"Invalid Number for given base {g}")
