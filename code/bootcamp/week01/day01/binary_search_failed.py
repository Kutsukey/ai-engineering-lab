def binary_search(arr,tar):
    leng = len(arr)
    guess = round(leng/2) 
    while arr[int(guess)] != tar:
        if guess < tar:
            arr = arr[guess:]
        else:
            arr = arr[:guess]
        guess = len(arr)/2
    print(guess)
    print(arr[int(guess)])


binary_search([1,2,3,4,5,6],2)