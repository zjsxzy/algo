def binary_search(arr, lo, hi, k):
    while lo <= hi:
        mid = (int)((lo + hi) / 2)
        if arr[mid] == k:
            return mid
        elif k < arr[mid]:
            hi = mid - 1
        else:
            lo = mid + 1
    return -1

def binary_search_recur(arr, lo, hi, k):
    if lo > hi:
        return -1
    mid = (int)((lo + hi) / 2)
    if arr[mid] == k:
        return mid
    elif k < arr[mid]:
        return binary_search_recur(arr, lo, mid - 1, k)
    else:
        return binary_search_recur(arr, mid + 1, hi, k)

if __name__ == '__main__':
    arr = [1, 2, 5, 19, 21]
    print(binary_search(arr, 0, len(arr) - 1, 5))
    print(binary_search_recur(arr, 0, len(arr) - 1, 5))