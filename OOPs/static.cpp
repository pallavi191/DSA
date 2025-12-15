// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Customer {
    int acc_number, balance;
    string name;

    // static data member declaration
    public:
    static int total_customers;
    Customer(int acc_number, int balance, string name) {
        this -> acc_number = acc_number;
        this -> balance = balance;
        this -> name = name;
        total_customers++;
    }
    Customer() {
        
    }
    void displayDetails() {
        cout << "Account Number: " << acc_number << " Balance: " << balance << " Name: " << name << endl;
    }

    void displayTotalCust() {
        cout << "Total Customers: " << total_customers ;
    }

};

// static data member initialization
int Customer :: total_customers = 0;

int main() {
    // Write C++ code here
    
    Customer C1 = Customer(123, 5000, "Pallavi");
    Customer C2 = Customer(123, 5000, "Pallavi");
    Customer C3 = Customer(123, 5000, "Pallavi");
    Customer C4 = Customer(123, 5000, "Pallavi");

    Customer C5 = Customer();
    C1.displayDetails();

    C1.displayTotalCust();
    Customer :: total_customers = 10; //accessible bcs its belong to class(if public) not obj
    C1.displayTotalCust();

    return 0;
}
