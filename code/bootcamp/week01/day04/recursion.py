def factorial(n):
    if n == 1 or n == 0: # Base Case
        return 1
    return n * factorial(n-1) # Recursive Case

# print(factorial(0))

def sum_list(arr, i=0):
    if len(arr) - 1 == i:
        return arr[i]
    sum = arr[i]
    i += 1
    return sum + sum_list(arr,i)
    
myList = [1,2,3,4,9]
# print(sum_list(myList))

def count_items(arr, i=1): # len veya kopyalama olmadan imkansız
    if arr == []:
        return 0
    elif i == len(arr):
        return 1
    return 1 + count_items(arr, i + 1)

empty = []
list_2 = [1,2,3,1,1,1]

print(count_items(empty))

def find_max(arr):
    pass