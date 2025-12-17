// #hybrid Level Inheritance
// | Inheritance Type | Present |
// | ---------------- | ------- |
// | Single           | ✔       |
// | Multiple         | ✔       |
// | Multilevel       | ✔       |
// | **Hybrid**       | ✔       |


#include <iostream>
using namespace std;

// Base class
class Student {
    public:
    Student() {
        cout << "I am student constructor" << endl;
    }
};

class Girl : public Student {
    public:
    Girl() {
        cout << "I am girl constructor" << endl;
    }
};

class Boy : public Student {
    public:
    Boy() {
        cout << "I am boy constructor" << endl;
    }
};

class Female : public Girl {
    public:
    Female() {
        cout << "I am female constructor" << endl;
    }
};

class Male : public Boy {
    public:
    Male() {
        cout << "I am male constructor" << endl;
    }
};

int main() {
    cout << "Girl obj called..." << endl;
    Girl g;
    cout << endl;
    cout << "Boy obj called..." << endl;
    Boy b;
    cout << endl;
    cout << "Female obj called..." << endl;
    Female f;
    cout << endl;
    cout << "Male obj called..." << endl;
    Male m;
    cout << endl;
    cout << "Student obj called..." << endl;
    Student s;
    return 0;
}

// output
// Girl obj called...
// I am student constructor
// I am girl constructor

// Boy obj called...
// I am student constructor
// I am boy constructor

// Female obj called...
// I am student constructor
// I am girl constructor
// I am female constructor

// Male obj called...
// I am student constructor
// I am boy constructor
// I am male constructor

// Student obj called...
// I am student constructor
