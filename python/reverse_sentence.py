def f():
    s1="the man is solid"
    arr1=[]
    temp=""
    for i in s1:
        if i==' ':
            arr1.append(temp)
            temp=""
        else:
            temp=temp+i
    if len(temp)!=0:
        arr1.append(temp)

    arr1.reverse()
    print(arr1)


if __name__ == "__main__":
    try:
        f()
    except EnvironmentError:
        print("env error")
    finally:
        print(True)

