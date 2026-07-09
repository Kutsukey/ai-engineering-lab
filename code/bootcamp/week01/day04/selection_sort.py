def selection_sort(arr):
    length = len(arr)
    res = []
    biggest = None
    i = 0
    j = 0
    while i < length:
        while j < len(arr):
            if biggest == None:
                biggest = arr[j]
            elif arr[j] > biggest:
                biggest = arr[j]
            j += 1   
        i += 1
        j = 0
        res.append(biggest)
        arr.remove(biggest)
        biggest = 0
    print(res)
        

myList = [3,1,2,5,4,9,6,8,7]
selection_sort(myList)


def selection_sort_revised(arr):
    j = 0
    smallest = None
    smallest_index = 0
    for i in range(len(arr)):
        j = i 
        while j < len(arr):
            if smallest == None:
                smallest = arr[j]
                smallest_index = j
            elif smallest > arr[j]:
                smallest = arr[j]
                smallest_index = j
            j+=1
        tmp = arr[i]
        arr[i] = arr[smallest_index]
        arr[smallest_index] = tmp
        smallest = None
        
    print(arr)
        
myList2 = [3,1,2,5]
selection_sort_revised(myList2)