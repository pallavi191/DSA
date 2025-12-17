// #hybrid Level Inheritance
// | Inheritance Type | Present |
// | ---------------- | ------- |
// | Single           | ✔       |
// | Multiple         | ✔       |
// | Multilevel       | ✔       |
// | **Hybrid**       | ✔       |

//           Vehicle
//          /       \
//   PetrolCar   ElectricCar
//          \       /
//             Car

// ✔️ Every multipath inheritance is hybrid
// ❌ Every hybrid inheritance is not necessarily multipath

#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    int speed;
public:
    Vehicle(int speed) : speed(speed) {
        cout << "Vehicle constructor called\n";
    }

    void display() {
        cout << "Speed: " << speed << endl;
    }
};

// Derived class 1 (virtual inheritance)
class PetrolCar : virtual public Vehicle {
protected:
    int fuelLevel;
public:
    PetrolCar(int speed, int fuel)
        : Vehicle(speed), fuelLevel(fuel) {
        cout << "PetrolCar constructor called\n";
    }
};

// Derived class 2 (virtual inheritance)
class ElectricCar : virtual public Vehicle {
protected:
    int batteryLevel;
public:
    ElectricCar(int speed, int battery)
        : Vehicle(speed), batteryLevel(battery) {
        cout << "ElectricCar constructor called\n";
    }
};

// Derived class 3 (Hybrid inheritance)
class Car : public PetrolCar, public ElectricCar {
public:
    Car(int speed, int fuel, int battery)
        : Vehicle(speed),        // ✅ Virtual base initialized HERE
          PetrolCar(speed, fuel),
          ElectricCar(speed, battery) {
        cout << "Car constructor called\n";
    }

    void display() {
        Vehicle::display(); // if you trying to call without virtual it will hit ambiguos err
        cout << "Fuel Level: " << fuelLevel << endl;
        cout << "Battery Level: " << batteryLevel << endl;
    }
};

int main() {
    Car c(120, 50, 80);
    c.display();
    return 0;
}

// output
// Vehicle constructor called
// PetrolCar constructor called
// ElectricCar constructor called
// Car constructor called
// Speed: 120
// Fuel Level: 50
// Battery Level: 80
