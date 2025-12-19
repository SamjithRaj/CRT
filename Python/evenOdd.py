ls = list(map(int, input().split()))

i = 0
j = len(ls)-1

while i < j:
    if(ls[i]%2 != 0 and ls[j]%2 == 0):
        ls[i], ls[j] = ls[j], ls[i]
        i+=1 
        j-=1
    if ls[i]%2 == 0 and ls[j]%2!=0:
        i+=1
        j-=1
    if ls[i]%2 != 0 and ls[j]%2!=0:
        j-=1
    if ls[i]%2 == 0 and ls[j]%2==0:
        i+=1

print(ls)