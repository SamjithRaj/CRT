a = list(map(int, input().split()))
k = int(input("Enter size of the window: "))
s = 0
mx = 0
mn = 0
mnw = mxw = 1  # Start from window 1

for i in range(k):
    s += a[i]
print(s, end=" ")
mx = s
mn = s

for i in range(len(a) - k):
    s = s - a[i] + a[i + k]
    if s > mx:
        mx = s
        mxw = i + 2  
    if s < mn:
        mn = s
        mnw = i + 2 
    print(s, end=" ")
print()
print("Max sum is:", mx)
print("Max sum window is window number:", mxw)
print("Min sum is:", mn)
print("Min sum window is window number:", mnw)
print()
