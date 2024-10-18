class LearnMySet:
    def __init__(self):
        self.my_set = {1, 2, 3}  # Store the set in the instance variable
        print(self.my_set)

        n = int(input("Enter a number: "))
        if n in self.my_set:
            print(f"The duplicate number is {n}")
        else:
            self.my_set.add(n)
            print(f"{n} was added to the set.")
            print("Updated set:", self.my_set)

        print(".......")
        print("Let's check if a set can store different data types.")
        self.my_set2 = {1, "vashu", 6.9}
        print(f"Set with different data types: {self.my_set2}")  # Print this inside the class
    
    

class LearnMyTuple:
    def __init__(self):
        self.my_tuple = (1, "name", 5.8)  # Store the tuple in the instance variable
        print(self.my_tuple)

    def typeis(self):
        print("the data type is tuple")

class LearnMyList:
    def __init__(self):
        self.my_list=[99,8,5,9,2,10,6]
        # self.my_list.sort()
    
    def sort_list(self):
        
        self.my_list.sort()
        


def list_comp_demo():
    my_list = []
    i = 1  # Start with 1
    while i < 50:
        my_list.append(i)
        i *= 2  # Multiply i by 2 in each iteration
    
    return my_list

# Correct syntax to check if the script is run directly
if __name__ == "__main__":
    # myset_instance = LearnMySet()  # Create an object of the class LearnMySet
    # print(f"Accessing my_set2 from outside: {myset_instance.my_set2}")  # Access instance variable
    # LearnMyTuple()  # Create an object of the class LearnMyTuple
    # mylist_obj = LearnMyList()
    # mylist_obj.my_list.append(1)
    # mylist_obj.my_list.sort()
    # mylist_obj.sort_list()
    # print(mylist_obj.my_list)
    my_list3=list_comp_demo()
    print(f"list3 {my_list3}")
    my_list4=[i**2 for i in range (1,6)]
    print(my_list4)
