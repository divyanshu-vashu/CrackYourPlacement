import numpy as np
arr = np.array(['apple', 'banana', 'cherry'])

# print(arr.dtype)

arr2 = np.array([1, 2, 3, 4], dtype='S')

print(arr2)
print(arr2.dtype)


arr = np.array([1.1, 2.1, 3.1])

newarr = arr.astype(int)

print(newarr)
print(newarr.dtype)

arr = np.array([1, 0, 3])

newarr = arr.astype(bool)

print(newarr)
print(newarr.dtype)