def isPrime(n):
    if n == 1 or n == 0:
        return False
    for i in range(2, int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

def rotate(n, cnt):
    last = n%10
    rem = n//10
    return last * (10**(cnt-1)) + rem

import math
n = int(input())
if n > 0:
    cnt = int(math.log10(n)) + 1
    loop = cnt
    rotPrCount = 0
    original = n

    while(loop):
        n = rotate(n, cnt)
        print(n)
        if isPrime(n):
            print(f"{n} is a rotated prime")
            rotPrCount += 1
            break
        if n == original:
            print("No rotated prime found")
            break
        loop -= 1

print(f"Total rotated prime count: {rotPrCount}")



