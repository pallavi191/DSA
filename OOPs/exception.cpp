// Exception
// An exception only affects the current try block.
// Once caught, program execution resumes normally.

#include <iostream>
#include <vector>
using namespace std;

class BankAcc {
    int amount, acc_no;
    string name;


    public:

    BankAcc(int amountValue, string cName, int accNo) : amount(amountValue), name(cName), acc_no(accNo)
    {};
    
    void Deposit(int value) {
        if(value <= 0) {
            throw "Amount can't be negative.";
        } else {
            amount += value;
            cout << "Updated Amount is: " << amount << endl;
        }
    }
    
    void Withdraw(int value) {
        if(value <= 0) {
            throw "Amount can't be negative.";
        } else if(value > amount) {
            throw "Your balance is low.";
        } else {
            amount -= value;
            cout << "Amount is withdrawn: " << amount << endl;
        }
    }
};

int main() {
    // Write C++ code here
    try {
        BankAcc B2(5000, "Pallavi", 10);
        B2.Deposit(500);
        B2.Deposit(200);
        B2.Withdraw(200);
        B2.Withdraw(5510);
    } catch(const char *e) {
        cout << "Exception occured: " << e << endl;
    }

    cout << endl;

    try {
        BankAcc B1(5000, "Pallavi", 10);
        B1.Deposit(500);
        B1.Deposit(0);
        B1.Deposit(200); // can't execute bcs exception already occured
    } catch(const char *e) {
        cout << "Exception occured: " << e << endl;
    }

    cout << endl;

    try {
        int a, b;
        cout << "Enter a ";
        cin >> a;
        cout << "Enter b ";
        cin >> b;
        if(b == 0) {
            throw string("value of b can't be 0: Divisible by 0 err");
        } else {
            cout << "ans: " << a/b << endl ;
        }
    } catch(const string s) {
        cout << "Exception occured: " << s << endl;
    }
    
    
    try {
        int *p = new int[1000000000000000];
        delete []p;
    } catch(const exception& e) {
        cout << "Exception occured: " << e.what() << endl; //std::bad_alloc
    }

    return 0;
}
