#include <bits/stdc++.h>
using namespace std;

class B {
public:
	double amt;
	int years;
	double r, i, t;
    
	void getValue() {
		cin >> amt >> years;
	}
	void compute() {
		if (amt <= 100000) {
			if (years >= 3) r = 7.5;
			else r = 6.0;
		} else if (amt <= 500000) {
			if (years >= 3) r = 8.25;
			else r = 7.5;
		} else {
			r = 7.5;
		}
		i = amt * r / 100.0 * years;
		t = amt + i;
	}
	void printAmount() {
		cout << "Rate: " << r << "\n";
		cout << "Interest: " << i << "\n";
		cout << "Total: " << t << "\n";
	}
};

int main() {
	B b;
	b.getValue();
	b.compute();
	b.printAmount();
	return 0;
}

