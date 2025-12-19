s = input("Enter the string: ")
s1 = input("Enter the substring: ")
k = len(s1)

cnt = 0
dicts1 = {}
for char in s1:
    dicts1[char] = dicts1.setdefault(char, 0) + 1
anaCount = 0

i = 0
j = 0
while j < len(s):
    if s[j] in dicts1:
        dicts1[s[j]] -= 1
        if dicts1[s[j]] == 0:
            cnt += 1                    
    if j - i + 1 < k:
        j += 1
    else:
        if cnt == len(dicts1):
            anaCount += 1
        if s[i] in dicts1:
            if dicts1[s[i]] == 0:
                cnt -= 1
            dicts1[s[i]] += 1
        i += 1
        j += 1
print(anaCount)




