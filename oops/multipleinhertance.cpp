#include <iostream>
using namespace std;

// Base class 1
class Animal {
public:
    Animal(string name) : name(name) {}
    void sound() {
        cout << name << " makes a sound." << endl;
    }
protected:
    string name;
};

// Base class 2
class Pet {
public:
    Pet(string owner) : owner(owner) {}
    void ownerDetails() {
        cout << "This pet is owned by " << owner << "." << endl;
    }
protected:
    string owner;
};

// Derived class inheriting from both Animal and Pet
class Dog : public Animal, public Pet {
public:
    Dog(string name, string breed, string owner) 
        : Animal(name), Pet(owner), breed(breed) {}

    void details() {
        cout << name << " is a " << breed << " owned by " << owner << "." << endl;
    }
private:
    string breed;
};

int main() {
    // Creating an instance of Dog
    Dog myDog("Buddy", "Golden Retriever", "John");

    // Accessing methods from both base classes
    myDog.details();       // Buddy is a Golden Retriever owned by John.
    myDog.sound();         // Buddy makes a sound.
    myDog.ownerDetails();  // This pet is owned by John.

    return 0;
}
