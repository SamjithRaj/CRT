#include<bits/stdc++.h>
using namespace std;

int main(){
    string name, addr; 
    double purchase; 
    char typePurchase; 
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Address: ";
    cin >> addr;
    cout << "Enter Purchase Amount: ";
    cin >> purchase;
    cout << "Enter Type of Purchase (L/D): ";
    cin >> typePurchase;
    double discount = 0.0;
    if(purchase>0 && purchase<=25000){
        if(typePurchase == 'L')
            discount = 0;
        if(typePurchase == 'D')
            discount = 0.05*purchase;
    }
    else if(purchase>25000 && purchase<=57000){
        if(typePurchase == 'L')
            discount = 0.05*purchase;
        if(typePurchase == 'D')
            discount = 0.075*purchase;
    }
    else if(purchase>57000  && purchase<=100000){
        if(typePurchase == 'L')
            discount = 0.075*purchase;
        if(typePurchase == 'D')
            discount = 0.1*purchase;
    }
    else if(purchase>100000){
        if(typePurchase == 'L'){
            discount = 0.1*purchase;
        }
        if(typePurchase == 'D'){
            discount = 0.15*purchase;
        }
    }
    double netAmt = purchase - discount;
    cout << "Name: " << name << endl;
    cout << "Address: " << addr << endl;
    cout << "Purchase Amount: " << purchase << endl;
    cout << "Net Amount: " << netAmt << endl;
    return 0;
}