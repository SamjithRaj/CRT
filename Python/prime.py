def isPrime(n):
    Flag = True
    if n == 1 or n == 0:
        return False
    for i in range(2, int(n//2)+1):
        if n%i == 0:
            Flag = False
    return Flag

ls = list(map(int, input().split()))

i = 0
j = len(ls)-1

while i<j:
    if(not isPrime(ls[i]) and isPrime(ls[j])):
        ls[i], ls[j] = ls[j], ls[i]
        i+=1
        j-=1
    if(isPrime(ls[i]) and isPrime(ls[j])):
        i+=1
    if( not isPrime(ls[i]) and not isPrime(ls[j])):
        j-=1
    if(isPrime(ls[i]) and not isPrime(ls[j])):
        i+=1
        j-=1

print(*ls)

    

