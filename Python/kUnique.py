s = input("Enter the string: ")
k = int(input("Enter the size of the window: "))

n = len(s)

sub = {}
i = 0
j = 0 
while j < n:
    sub.setdefault(s[j], 0)
    sub[s[j]] += 1
    if j - i + 1 == k:
        if len(sub) == k:
            print(s[i:j+1])
        sub[s[i]] -= 1
        if sub[s[i]] == 0:
            del sub[s[i]]
        i += 1
    j += 1
