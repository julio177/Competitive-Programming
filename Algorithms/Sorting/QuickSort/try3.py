def partition(arr, low, high):
    index = low - 1
    piv = arr[high]

    for i in range(low, high):
        if arr[i] < piv:
            index += 1
            arr[index], arr[i] = arr[i], arr[index]
    index += 1
    arr[index], arr[high] = arr[high], arr[index]
    return index

def quick(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        quick(arr, low, pi - 1)
        quick(arr, pi + 1, high)
    return arr

def main():
    a = [5, 2, 4, 3, 7, 9, 8]
    print(quick(a, 0, len(a) - 1))

main()