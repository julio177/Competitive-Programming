def partition(arr, l, h):
    i = l - 1
    piv = arr[h]

    for x in range(l, h):
        if arr[x] <= piv:
            i += 1
            arr[i], arr[x] = arr[x], arr[i]
    i += 1
    arr[i], arr[h] = arr[h], arr[i]
    return i

def quick_sort(arr, l, h):
    if l < h:
        pi = partition(arr, l, h)
        quick_sort(arr, l, pi - 1)
        quick_sort(arr, pi + 1, h)


def main():
    a = [5, 2, 6, 7, 4, 9, 0, 3]
    quick_sort(a, 0, len(a) - 1)
    print(a)

main()