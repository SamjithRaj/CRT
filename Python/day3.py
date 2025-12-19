p=4
q=4
n=4
for i in range(n+3):
    for j in range((n*2)+1):
        if(j<p and j>q):
            print('*',end=' ')
        else:
            print('@',end=' ')
    print()
    if(i>4):
        p+=1
        q-=1
    else:
        p-=1
        q+=1

a=1
for i in range(5):
    for j in range(6):
        if(i%2==0 and j<5):
            print(a,end=' ')
        elif(i%2==0 and j>4):
            print(a+1,end=' ')
        elif(i%2!=0 and j>0):
            print(a,end=' ')    
        else:
            print(a+1,end=' ')
    print()
    a+=1

p=3
q=3
for i in range(7):
    for j in range(7):
        if(j>p and j<q):
            print('* ',end='')
        else:
            print(' ',end='')
    print()
    if(i>2):
        p+=1
        q-=1
    else:
        p-=1
        q+=1