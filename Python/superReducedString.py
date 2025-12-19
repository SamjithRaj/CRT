#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'superReducedString' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def superReducedString(s):
    # Write your code here
    result = []
    
    for char in s:
        if result and result[-1] == char:
            result.pop()
        else:
            result.append(char)
            
    final = "".join(result)
    
    if final == "":
        return "Empty String"
    else:
        return final

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = superReducedString(s)

    fptr.write(result + '\n')

    fptr.close()

