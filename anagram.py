s1 = input("Enter the first string: ")
s2 = input("Enter the second string: ")

if len(s1) != len(s2):
    print("Not anagrams")
    exit()

dicts1 = {}

for char in s1:
    dicts1[char] = dicts1.setdefault(char, 0) + 1

for char in s2:
    if char in dicts1:
        dicts1[char] -= 1

for key in dicts1:
    if dicts1[key] != 0:
        print("Not anagrams")
        exit()

print("Anagrams")