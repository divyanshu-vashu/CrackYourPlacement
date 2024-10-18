# Parent class (also called base or super class)
class Animal:
    def __init__(self, name):
        self.name = name
    
    def speak(self):
        print(f"{self.name} makes a sound.")

# Child class (also called derived or subclass) inheriting from Animal
class Dog(Animal):
    def __init__(self, name, breed):
        # Calling the parent class constructor
        super().__init__(name)
        self.breed = breed
    
    # Overriding the parent class method
    def speak(self):
        print(f"{self.name} barks.")

# Creating an instance of the Dog class
dog1 = Dog("Buddy", "Golden Retriever")
dog1.speak()  # Output: Buddy barks.
