def partition(arr, low, high):
    '''Sorts last element of arr in correct index'''
    # starting point to sort (-1)
    index = low - 1
    # value to compare every other element
    pivot = arr[high]
    # high not inclusive
    for i in range(low, high):
        if arr[i] <= pivot:
            index += 1
            # swap vals of starting point and current
            arr[index], arr[i] = arr[i], arr[index]
    # swap last value (pivot) with current index count
    index += 1
    arr[index], arr[high] = arr[high], arr[index]
    return index

def quick_sort(arr, low, high):
    '''Recursive sort'''
    if low < high:
        partition_index = partition(arr, low, high)
        quick_sort(arr, low, partition_index - 1)
        quick_sort(arr, partition_index + 1, high)


def main():
    nums = [6, 5, 1, 3, 8, 4, 7, 9, 2]
    quick_sort(nums, 0, len(nums) - 1)
    print(nums)

main()
