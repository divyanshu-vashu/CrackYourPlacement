#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void sound() {
        cout << "Animal sound\n";
    }
     void print(){
        cout<<"this is not virtual\n";
    }
};

// Derived class - Dog
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks: Woof Woof!\n";
    }
};

int main() {
    Animal* animalPtr;
    Dog dog;

    // Point to Dog object
    animalPtr = &dog;
    // First, call the Animal sound directly
    animalPtr->Animal::sound(); // Calls Animal's sound()
    // Then, call the overridden Dog sound
    animalPtr->sound(); // Calls Dog's sound() due to virtual function
    animalPtr->print();

    return 0;
}
