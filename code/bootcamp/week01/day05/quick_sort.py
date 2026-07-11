# subarray + pivot + subarray
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    
    pivot_index = len(arr) // 2
    pivot = arr[pivot_index]
    lesser_subarray = []
    greater_subarray = []

    for i,e in enumerate(arr):
        if i == pivot_index:
            continue
        if e <= pivot:
            lesser_subarray.append(e)
        else:
            greater_subarray.append(e)
    res = []
    res.extend(quick_sort(lesser_subarray))
    res.append(pivot)
    res.extend(quick_sort(greater_subarray))
    return res

myList = [3,2,1,4,4,4,4,4,5,0,0,0]

print(quick_sort(myList))
print(myList)