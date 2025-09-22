#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    n = len(arr)
    Pos = 0
    Neg = 0
    Zero = 0
    
    for num in arr:
        if num > 0:
            Pos += 1
        elif num < 0:
            Neg += 1
        else:
            Zero += 1
    print(f"{Pos / n:.6f}")
    print(f"{Neg / n:.6f}")
    print(f"{Zero / n:.6f}")

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
