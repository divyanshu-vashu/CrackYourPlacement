# Function with args and kwargs
def sample_func(*args, **kwargs):
    print("Arguments passed through *args:")
    for arg in args:
        print(arg)
    
    print("Arguments passed through **kwargs:")
    for key, value in kwargs.items():
        print(f"{key} = {value}")

# Calling with both args and kwargs
sample_func(10, 20, 30, name="Alice", location="Wonderland")
