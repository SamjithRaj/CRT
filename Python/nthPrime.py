def isPrime(n):
    if n == 1 or n == 0:
        return False
    for i in range(2, int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

n = int(input())
c = 0
i = 2
while c<n:
    if isPrime(i):
        print(i, end=" ")
        c+=1
    i+=1

