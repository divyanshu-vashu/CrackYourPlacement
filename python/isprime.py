import math

def isprime(n):
    if n < 2:
        print("no")
        return
    if n == 2 or n == 3:
        print("yes")
        return
    if n % 2 == 0 or n % 3 == 0:
        print("no")
        return
    
    # Check for factors from 5 to sqrt(n)
    for i in range(5, int(math.sqrt(n)) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            print("no")
            return
    
    print("yes")

n = 61
isprime(n)
isprime(100)
