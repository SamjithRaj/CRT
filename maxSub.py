arr = list(map(int, input().split()))
k = int(input())

i = 0
curr_s = 0
max_s = 0

for j in range(len(arr)):
    curr_s = curr_s + arr[j]
    if j - i + 1 == k:
        if curr_s > max_s:
            max_s = curr_s
        curr_s = curr_s - arr[i]
        i = i + 1

print(f"Maximum Sum Subarray of Size K: {max_s}")