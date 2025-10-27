#ls = [5, 2, 1, 6]
#o/p : [11, 3, 2, 13]

def isPrime(n):
    if n == 1 or n == 0:
        return False
    for i in range(2, int(n**0.5)+1):
        if n%i == 0:
            return False
    return True


ls = list(map(int, input().split()))
output = []

for n in ls:
    c = 0
    i = 2
    while c<n:
        if isPrime(i):
            c+=1
        i+=1
    output.append(i-1)

print(output)
