import numpy as np
arr=np.array([1,2,3,4,5])

# print(np.__version__)
# print(arr)
# print(type(arr))

arr2 = np.array(42) #0d array
# print(arr2)
arr3 = np.array([[1, 2, 3], [4, 5, 6]])

# print(arr3)
a = np.array(42)
b = np.array([1, 2, 3, 4, 5])
c = np.array([[1, 2, 3], [4, 5, 6]])
d = np.array([[[1, 2, 3], [4, 5, 6]], [[1, 2, 3], [4, 5, 6]]])

# print(a.ndim)
# print(b.ndim)
# print(c.ndim)
# print(d.ndim)

arr4 = np.array([1, 9, 3, 10, 5, 6, 7]) #silicing 

print(arr4[1:5])
print(arr4[2:])
print(arr4[:3])
