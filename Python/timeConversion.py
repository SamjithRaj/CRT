#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    time = s[-2:]
    hour = int(s[:2])
    mid = s[2:-2]

    if time == 'PM' and hour != 12:
        hour += 12
    elif time == 'AM' and hour == 12:
        hour = 0
    
    return f'{hour:02d}{mid}'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
