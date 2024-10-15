def f():
    # List of strings
    my_list = ['Hello', 'world', 'this', 'is', 'Python']

# Convert list to string using join()
    result = ' '.join(my_list)

    print(result)

def nonstring():
    my_list = [1, 2, 3, 4]

# Convert list of integers to string
    result = ''.join(map(str, my_list))

    print(result)

if __name__ == "__main__":
    f()
    nonstring()