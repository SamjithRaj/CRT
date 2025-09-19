s1 = input("Enter first string: ")
s1 = s1.replace(" ", "").lower()

for i in s1:
    if '0' <= i <= '9' or not('a' <= i <= 'z'):
        s1 = s1.replace(i, "")

dicts1 = {}

for char in s1:
    dicts1[char] = dicts1.setdefault(char, 0) + 1
if len(dicts1) == 26:
    print("Pangram")
else:
    print("Not pangram")
