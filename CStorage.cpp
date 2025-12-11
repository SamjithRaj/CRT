#include<bits/stdc++.h>
using namespace std;

class CloudStorage {
private:
    int acno;
    int space;
    double bill;

public:
    CloudStorage() {
        acno = 0;
        space = 0;
        bill = 0.0;
    }

    CloudStorage(int a, int s) {
        acno = a;
        space = s;
        bill = 0.0;
    }
    void accept() {
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter Storage Space (in GB): ";
        cin >> space;
    }

    void calculate() {
        if (space <= 15) {
            bill = space * 15;
        }
        else if (space <= 30) {
            bill = (15 * 15) + ((space - 15) * 13);
        }
        else {
            bill = (15 * 15) + (15 * 13) + ((space - 30) * 11);
        }
    }
    void display() {
        cout << "Account Number: " << acno << endl;
        cout << "Storage Space: " << space << " GB" << endl;
        cout << "Bill to be Paid: Rs " << bill << endl;
    }
};

int main() {
    CloudStorage cs;
    cs.accept();
    cs.calculate();
    cs.display();

    return 0;
}