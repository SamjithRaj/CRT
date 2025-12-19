temp = []
def addLs(ls, x):
    if not ls or ls[-1] <= x: # Base case: list is empty or x is greater than or equal to the last element
        ls.append(x)
        ls.extend(reversed(temp)) # Add back elements from temp in correct order
        temp.clear() # Clear temp for future calls
        return ls
    else: # Recursive case: last element is greater than x
        temp.append(ls.pop())
        return addLs(ls,x)

print(addLs([1,2,4,5], 3))
