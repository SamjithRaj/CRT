#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gemstones' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING_ARRAY arr as parameter.
#

def gemstones(arr):
    # Write your code here
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    gems = 0
    
    n = 0
    for rock in arr:
        n = n + 1

    for mineral in alphabet:
        is_gemstone = 1
        
        rock_index = 0
        while rock_index < n:
            current_rock = arr[rock_index]
            found = 0
            
            for char in current_rock:
                if char == mineral:
                    found = 1
                    break
            
            if found == 0:
                is_gemstone = 0
                break
            
            rock_index = rock_index + 1
            
        if is_gemstone == 1:
            gems = gems + 1
            
    return gems

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr_item = input()
        arr.append(arr_item)

    result = gemstones(arr)

    fptr.write(str(result) + '\n')

    fptr.close()

