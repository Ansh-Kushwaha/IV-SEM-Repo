def merge(arr, low, mid, high):
    m = mid - low + 1
    n = high - mid
    left = [0] * m
    right = [0] * n

    for i in range(0, m):
        left[i] = arr[low + i]
    for j in range(0, n):
        right[j] = arr[mid + j + 1]

    i, j, k = 0, 0, low

    while i < m and j < n :
        if left[i] <= right[j] :
            arr[k] = left[i]
            i += 1
        else :
            arr[k] = right[j]
            j += 1
        k += 1
    
    while i < m :
        arr[k] = left[i]
        i += 1
        k += 1
    while j < n :
        arr[k] = right[j]
        j += 1
        k += 1

def mergeSort(arr, low, high):
    if low < high :
        mid = (low + high) // 2
        mergeSort(arr, low, mid)
        mergeSort(arr, mid + 1, high)
        merge(arr, low, mid, high)

arr = [12, 43, 21, 53, 85]
mergeSort(arr, 0, len(arr) - 1)

for i in range(0, len(arr)):
    print(arr[i])

