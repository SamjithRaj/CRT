#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'anagram' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def anagram(s):
    # Write your code here
    n = len(s)
    if n % 2 != 0:
        return -1
    
    mid = n // 2
    s1 = s[0:mid]
    s2 = s[mid:n]
    
    counts1 = {}
    for char in s1:
        counts1[char] = counts1.get(char, 0) + 1
        
    for char in s2:
        if char in counts1 and counts1[char] > 0:
            counts1[char] -= 1
            
    changes = 0
    for count in counts1.values():
        changes += count
        
    return changes

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = anagram(s)

        fptr.write(str(result) + '\n')

    fptr.close()

