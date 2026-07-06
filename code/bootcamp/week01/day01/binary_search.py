def binary_search(arr,tar):
    low = 0
    high = len(arr) - 1
    
    while low <= high:
        mid = (low + high)//2
        guess = arr[mid]

        if guess == tar:
            return mid
        if guess > tar:
            high = mid - 1
        else:
            low = mid + 1

    return None
