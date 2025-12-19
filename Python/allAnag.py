s = input()
subStr = input()

k = len(subStr)
subStr_counts = {}
s_counts = {}
res = []

for char_subStr in subStr:
    if char_subStr in subStr_counts:
        subStr_counts[char_subStr] = subStr_counts[char_subStr] + 1
    else:
        subStr_counts[char_subStr] = 1

i = 0
for j in range(len(s)):
    char_j = s[j]
    if char_j in s_counts:
        s_counts[char_j] = s_counts[char_j] + 1
    else:
        s_counts[char_j] = 1

    if j - i + 1 == k:
        if s_counts == subStr_counts:
            res = res + [i]
        
        char_i = s[i]
        s_counts[char_i] = s_counts[char_i] - 1
        if s_counts[char_i] == 0:
            del s_counts[char_i]
        i = i + 1

print(res)