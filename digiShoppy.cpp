#include<bits/stdc++.h>
using namespace std;

class SALES {
private:
    string name;
    double cost;
    double discount, tax, payable;

public:
    SALES() {
        name = "";
        cost = 0;
        discount = 0;
        tax = 0;
        payable = 0;
    }

    SALES(string custName, double custCost) {
        name = custName;
        cost = custCost;
        discount = 0;
        tax = 0;
        payable = 0;
    }

    void calc() {
        double discountAmount = 0;
        
        if (cost > 50000) {
            discountAmount = cost * 0.20;
        }
        else if (cost >= 40000 && cost <= 50000) {
            discountAmount = cost * 0.18;
        }
        else if (cost >= 30000 && cost < 40000) {
            discountAmount = cost * 0.15;
        }
        else if (cost >= 20000 && cost < 30000) {
            discountAmount = cost * 0.10;
        }
        
        discountAmount = discountAmount + (cost * 0.05);
        
        double afterDiscount = cost - discountAmount;
        tax = afterDiscount * 0.12;
        payable = afterDiscount + tax;
    }

    void print() {
        cout << "Customer: " << name << endl;
        cout << "Cost: " << cost << endl;
        cout << "Amount to Pay: " << payable << endl;
    }
};

int main() {
    SALES s;
    
    cout << "Enter name: ";
    string custName;
    cin >> custName;
    
    cout << "Enter cost: ";
    double custCost;
    cin >> custCost;
    
    s = SALES(custName, custCost);
    s.calc();
    s.print();
    
    return 0;
}