n=int(input("enter n for fibonic\n"))

a=1
b=1
if n==1:
    print(1)
elif n==2:
    print(str(1) + " " + str(1))
else:
    print(f"1 1",end=' ')
    for _ in range(n-2):
        temp=a+b
        print(f"{temp}",end=' ')
        a=b
        b=temp


