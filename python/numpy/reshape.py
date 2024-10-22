import numpy as np

arr = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])

newarr = arr.reshape(2, 3, 2)

print(newarr)

arr2 = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,9])

# newarr2 = arr.reshape(2, 3, 2) #array to will have error because it can't shape into 2,3,2

# print(newarr2)