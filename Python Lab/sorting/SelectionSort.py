# Selection Sort
def selectionSort(arr):
    n = len(arr)
    if n <= 1 :
        return

    for i in range(0, n-1):
        minIdx = i
        for j in range(i + 1, n):
            if arr[j] < arr[minIdx] :
                minIdx = j
        if minIdx != i :
            arr[minIdx], arr[i] = arr[i], arr[minIdx]

arr = [45, 12, 84, 36, 64]
selectionSort(arr)

print(arr)