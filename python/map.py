def main():
    mp = {}
    arr = [6, 7, 5, 4, 3, 45, 6, 7, 876, 5, 433, 4, 56, 67, 4, 4325, 6, 7444, 678]

    # Create a frequency map
    for num in arr:
        if num in mp:
            mp[num] += 1
        else:
            mp[num] = 1

    # Print the elements and their frequency
    for key, value in mp.items():
        print(f"{key} {value}")

if __name__ == "__main__":
    main()
