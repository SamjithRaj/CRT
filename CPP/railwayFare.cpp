#include <iostream>
#include <string>

using namespace std;

class Railways {
public:
    string name;
    int age;
    int dist;
    int fare;

    Railways() {
        name = "";
        age = 0;
        dist = 0;
        fare = 0;
    }

    Railways(string n, int a, int d) {
        name = n;
        age = a;
        dist = d;
        fare = 0;
    }

    void calculateFare() {
        if (age < 10) {
            if (dist < 10) {
                fare = 5;
            } else if (dist <= 50) {
                fare = 20;
            } else {
                fare = 50;
            }
        } else if (age <= 60) {
            if (dist < 10) {
                fare = 10;
            } else if (dist <= 50) {
                fare = 40;
            } else {
                fare = 80;
            }
        } else {
            if (dist < 10) {
                fare = 40;
            } else if (dist <= 50) {
                fare = 15;
            } else {
                fare = 35;
            }
        }
    }

    void display() {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Distance: " << dist << " km\n";
        cout << "Fare: Rs. " << fare << "\n";
    }
};

int main() {
    string n;
    int a;
    int d;

    cout << "Enter name:\n";
    cin >> n;
    cout << "Enter age:\n";
    cin >> a;
    cout << "Enter distance (km):\n";
    cin >> d;

    Railways r(n, a, d);
    r.calculateFare();
    r.display();

    return 0;
}