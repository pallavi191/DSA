// #Hierarchical Level Inheritance
// one parent - multiple children
#include <iostream>
using namespace std;

class Human {
    protected:
    int age;
    string name;

    public:
    Human() {
        
    }
    Human(int age, string name) {
        this -> age = age;
        this -> name = name;
    }

    void display() {
        cout << "Age: " << age << " Name: " << name << endl;
    }
};

class Teacher : public Human {
    int salary;

    public:
    Teacher(int age, int salary, string name) : Human(age, name) {
        this -> salary = salary;
    }

    void display() {
        cout << "Salary: " << salary << endl;
        Human::display(); //base class function access
    }
};


class Student : public Human {
    int fees;

    public:
    Student(int age, int fees, string name) {
        this -> fees = fees;
        this -> age = age;
        this -> name = name;
    }

    void display() {
        cout << "Fees: " << fees << endl;
        Human::display(); //base class function access
    }
};

int main() {
    Teacher t1(25, 20000, "Pallavi");
    cout << "Teacher called..." << endl;
    t1.display();

    cout << endl;

    Student s1(25, 500, "Pallavi");
    cout << "Student called..." << endl;
    s1.display();
    
    // output:
    // Teacher called...
    // Salary: 20000
    // Age: 25 Name: Pallavi
    
    // Student called...
    // Fees: 500
    // Age: 25 Name: Pallavi


    return 0;
}
