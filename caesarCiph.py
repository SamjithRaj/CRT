#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'caesarCipher' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER k
#

def caesarCipher(s, k):
    # Write your code here
    cipher = ""
    
    k = k % 26

    for char in s:
        code = ord(char)
        
        is_upper = code >= 65 and code <= 90
        is_lower = code >= 97 and code <= 122

        if is_upper:
            new = code + k
            if new > 90:
                new = new - 26
            cipher = cipher + chr(new)
        elif is_lower:
            new = code + k
            if new > 122:
                new = new - 26
            cipher = cipher + chr(new)
        else:
            cipher = cipher + char
            
    return cipher

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()

