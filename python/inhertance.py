# Parent class 1
class Animal:
    def __init__(self, name):
        self.name = name

# Parent class 2
class Pet:
    def __init__(self, owner):
        self.owner = owner

# Child class inheriting from both Animal and Pet
class Dog(Animal, Pet):
    def __init__(self, name, owner, breed):
        Animal.__init__(self, name)  # Initialize Animal part
        Pet.__init__(self, owner)    # Initialize Pet part
        self.breed = breed

    def details(self):
        print(f"{self.name} is a {self.breed} and is owned by {self.owner}.")

# Creating an instance
dog1 = Dog("Buddy", "John", "Golden Retriever")
dog1.details()  # Output: Buddy is a Golden Retriever and is owned by John.
