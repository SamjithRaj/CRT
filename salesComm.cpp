#include<bits/stdc++.h>
using namespace std;

int main() {
    double sales, comm;
    
    cout << "Enter sales amount: ";
    cin >> sales;
    
    if (sales > 100000) {
        comm = sales * 0.25;
    }
    else if (sales >= 80000) {
        comm = sales * 0.225;
    }
    else if (sales >= 60000) {
        comm = sales * 0.20;
    }
    else if (sales >= 40000) {
        comm = sales * 0.15;
    }
    else {
        comm = sales * 0.125;
    }
    
    cout << "Sales: " << sales << endl;
    cout << "Commission: " << comm << endl;
    
    return 0;
}
