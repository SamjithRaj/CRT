def pow(n, p):
    if(p):
        return n*pow(n, p-1)
    else:
        return 1
    
print(pow(2, 3))