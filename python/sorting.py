def bubble_sort(arr):
    n = len(arr)
    # Traverse through all elements in the array
    for i in range(n):
        # Last i elements are already in place
        for j in range(0, n-i-1):
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

def selection_sort(arr):
    n = len(arr)
    # Traverse through all array elements
    for i in range(n):
        # Find the minimum element in remaining unsorted array
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

def insertion_sort(arr):
    n = len(arr)
    # Traverse through 1 to len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i-1
        # Move elements of arr[0..i-1], that are greater than key,
        # to one position ahead of their current position
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Example usage
if __name__ == "__main__":
    # Test the sorting functions
    test_array_bubble = [64, 34, 25, 12, 22, 11, 90]
    bubble_sort(test_array_bubble)
    print("Bubble Sorted array is:", test_array_bubble)

    test_array_selection = [64, 25, 12, 22, 11]
    selection_sort(test_array_selection)
    print("Selection Sorted array is:", test_array_selection)

    test_array_insertion = [12, 11, 13, 5, 6]
    insertion_sort(test_array_insertion)
    print("Insertion Sorted array is:", test_array_insertion)
