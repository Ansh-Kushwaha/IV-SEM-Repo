def maxHeapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < n and arr[l] > arr[largest] :
        largest = l
    if r < n and arr[r] > arr[largest] :
        largest = r
    
    if largest is not i :
        arr[i], arr[largest] = arr[largest], arr[i]
        maxHeapify(arr, n, largest)

def heapSort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        maxHeapify(arr, n, i)
    
    for j in range (n - 1, 0, -1):
        arr[j], arr[0] = arr[0], arr[j]
        maxHeapify(arr, j, 0)

arr = [8, 9, 1, 3, 5, 2, 4, 7, 6]
heapSort(arr)

for i in range(len(arr)):
    print(arr[i])