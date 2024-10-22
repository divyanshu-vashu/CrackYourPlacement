import numpy as np

arr = np.array([1, 2, 3, 4, 5])
x = arr.copy() #if u cange original , copy won't affect 
arr[0] = 42

print(arr)
print(x)

arr = np.array([1, 2, 3, 4, 5])
x = arr.view() #if u change original , duplicate also changed 
arr[0] = 42

print(arr)
print(x)


arr = np.array([1, 2, 3, 4, 5])

x = arr.copy()
y = arr.view()

print(x.base)
print(y.base)