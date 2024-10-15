try:
    num1=int(input())
    num2=int(input())
    result=num1/num2
except ZeroDivisionError:
    print("can't diveide with zero")
else:
    print(f"{result:.2f}")
finally:
    print("finally block exceuted")