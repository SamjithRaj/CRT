#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'theLoveLetterMystery' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def theLoveLetterMystery(s):
    # Write your code here
    cnt = 0
    n = len(s)
    
    i = 0
    j = n - 1
    
    while i < j:
        left = ord(s[i])
        right = ord(s[j])
        
        change = abs(left - right)
        cnt = cnt + change
        
        i = i + 1
        j = j - 1
        
    return cnt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = theLoveLetterMystery(s)

        fptr.write(str(result) + '\n')

    fptr.close()

