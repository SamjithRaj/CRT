#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'separateNumbers' function below.
#
# The function accepts STRING s as parameter.
#

def separateNumbers(s):
    # Write your code here
    n = len(s)
    
    if n == 1:
        print("NO")
        return

    i = 1
    while i <= n // 2:
        first = s[0:i]
        first_num = int(first)
        
        new = ""
        curr = first_num
        
        while len(new) < n:
            new = new + str(curr)
            curr = curr + 1
            
        if new == s:
            print("YES " + first)
            return
            
        i = i + 1

    print("NO")

if __name__ == '__main__':
    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        separateNumbers(s)

