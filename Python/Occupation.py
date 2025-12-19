gList = []

def parentChild(occupation, level):
    gList.append(occupation)
    
    if level < n:
        parentChild(occupation + '0', level + 1)
        parentChild(occupation + '1', level + 1)

n = int(input())
k = int(input())
parentChild('', 0)

if 0 < k <= len(gList):
    print(gList[k[k-1]])
else:
    print("Invalid k")