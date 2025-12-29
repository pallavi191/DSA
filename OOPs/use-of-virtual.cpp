// Polymerphism - run time polymorphism - virtual keyword
#include <iostream>
#include <vector>
using namespace std;

class Animal {
    public:
    virtual void speak() {
        cout << "Animal speaking..." << endl;
    }
};

class Dog: public Animal {
    public:
    void speak() {
        cout << "Dog speaking - bark..." << endl;
    }
};

class Cat: public Animal {
    public:
    void speak() {
        cout << "Cat speaking - meow..." << endl;
    }
};
int main() {
    // Write C++ code here

    vector<Animal*>animalsList;
    
    animalsList.push_back(new Cat());
    animalsList.push_back(new Cat());
    animalsList.push_back(new Animal());
    animalsList.push_back(new Dog());
    animalsList.push_back(new Dog());
    
    for(int i = 0; i < animalsList.size(); i++) {
        // (*animalsList[i]).speak();
        animalsList[i] -> speak();
        // Thanks to the virtual keyword, the correct speak() function is called
        // at runtime based on the actual object type (Animal, Dog, or Cat).

    }

    for(auto a : animalsList) delete a; // release memory

    return 0;
}
