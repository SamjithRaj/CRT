target = int(input())
nums = list(map(int, input().split()))

res = float('inf')
curr_s = 0
i = 0
j = 0

while j < len(nums):
    curr_s += nums[j]
    
    while curr_s >= target:
        res = min(res, j - i + 1)
        curr_s -= nums[i]
        i += 1

    j += 1

if res == float('inf'):
    res = 0

print(res)