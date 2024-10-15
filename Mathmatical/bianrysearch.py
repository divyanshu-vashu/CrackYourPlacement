def binarysearch(a, find, start, end):
    if start > end:
        return -1  # Return -1 if the element is not found

    mid = (start + end) // 2  # Use integer division

    if a[mid] == find:
        return mid
    elif find < a[mid]:
        return binarysearch(a, find, start, mid - 1)  # Ensure proper return
    else:
        return binarysearch(a, find, mid + 1, end)  # Ensure proper return


a = [2, 5, 7, 12, 56, 3, 5, 89, 6, 23]
a.sort()
find = int(input("Enter the number to find: \n"))
ans = binarysearch(a, find, 0, len(a) - 1)  # Use len(a) instead of a.size()

if ans != -1:
    print(f"Element found at index {ans}")
else:
    print("Element not found")
