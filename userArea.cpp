#include <iostream>
#include <iomanip>
using namespace std;

double area(double r) { return 3.14159265358979323846 * r * r; }
double area(int a) { return (double)a * a; }
double area(double l, double b) { return l * b; }

int main() {
    int choice;
    cout << "1. Circle\n2. Square\n3. Rectangle\nEnter choice: ";
    cin >> choice;
    cout << fixed << setprecision(2);
    switch (choice) {
        case 1: {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            cout << "Area = " << area(r) << "\n";
            break;
        }
        case 2: {
            int s;
            cout << "Enter side: ";
            cin >> s;
            cout << "Area = " << area(s) << "\n";
            break;
        }
        case 3: {
            double l, b;
            cout << "Enter length and breadth: ";
            cin >> l >> b;
            cout << "Area = " << area(l, b) << "\n";
            break;
        }
        default:
            cout << "Invalid choice\n";
    }
    return 0;
}