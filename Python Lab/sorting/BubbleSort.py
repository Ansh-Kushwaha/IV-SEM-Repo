# Bubble Sort
def bubbleSort(arr):
    n = len(arr)
    flag = False

    for i in range (n-1):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                flag = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
            if not flag:
                return

arr = [5, 3, 1, 2 , 6, 4]
bubbleSort(arr)

print(arr)
