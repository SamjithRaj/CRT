
    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        double inc;
        cin >> inc; 
        double tax=0;
        if (inc <= 600000) {
            tax = inc * 7.5 / 100.0;
        } else if (inc <= 1000000) {
            tax = (inc - 600000) * 10.0 / 100.0;
        } else if (inc <= 1500000) {
            tax = 10000 + (inc - 1000000) * 20.0 / 100.0;
        } else {
            tax = 20000 + (inc - 1500000) * 30.0 / 100.0;
        }
        double net = inc - tax;
        cout << "Tax: " << tax << "\n";
        cout << "Net: " << net << "\n";
        return 0;
    }
}
    