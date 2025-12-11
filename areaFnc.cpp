#include<bits/stdc++.h>
using namespace std;

class Area {
public:
    double area(double a, double b, double c) {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double area(int a, int b, int h) {
        return 0.5 * h * (a + b);
    }

    double area(double d1, double d2) {
        return 0.5 * (d1 * d2);
    }
};

int main() {
    Area obj;
    double x;

    cout << "Area Calculator" << endl << endl;

    cout << "Triangle" << endl;
    x = obj.area(5.0, 6.0, 7.0);
    cout << "Area: " << x << endl << endl;

    cout << "Trapezium" << endl;
    x = obj.area(10, 15, 8);
    cout << "Area: " << x << endl << endl;

    cout << "Rhombus" << endl;
    x = obj.area(12.0, 16.0);
    cout << "Area: " << x << endl;

    return 0;
}
