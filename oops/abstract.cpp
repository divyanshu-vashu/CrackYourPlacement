#include <iostream>
using namespace std;

// Abstract Base class
class Animal {
public:
    // Pure virtual function, making this an abstract class
    virtual void sound() = 0;
    
};

// Derived class - Dog
class Dog : public Animal {
public:
    void sound()  {
        cout << "Dog barks: Woof Woof!\n";
    }
};

// Derived class - Cat
class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows: Meow Meow!\n";
    }
};

int main() {
    // Animal animal; // This would be an error as Animal is an abstract class
    Animal* animalPtr;

    Dog dog;
    Cat cat;

    // Point to Dog object
    animalPtr = &dog;
    animalPtr->sound(); // Calls Dog's sound()
    
    // dog.Animal::sound();
    // Point to Cat object
    animalPtr = &cat;
    animalPtr->sound(); // Calls Cat's sound()

    return 0;
}
