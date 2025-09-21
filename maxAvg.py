nums = list(map(int, input().split()))
k = int(input())

i = 0
curr_s = 0
max_s = -1000000000

for j in range(len(nums)):
    curr_s = curr_s + nums[j]
    if j - i + 1 == k:
        if curr_s > max_s:
            max_s = curr_s
        curr_s = curr_s - nums[i]
        i = i + 1

res = max_s / k
print(f"3. Maximum Average Subarray I: {res}")