#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int floorNum;
    char roomClass;
    cout << "Enter floor number (1-3): ";
    cin >> floorNum;
    cout << "Enter room class (A-C): ";
    cin >> roomClass;
    roomClass = toupper(roomClass);
    int price = 0;
    if (floorNum == 1) {
        if (roomClass == 'A') {
        price = 750; 
        }
        else if (roomClass == 'B') { 
            price = 600; 
        }
        else if (roomClass == 'C') { 
            price = 500; 
        }
    }
     else if (floorNum == 2) {
        if (roomClass == 'A') { 
            price = 1200; 
        }
        else if (roomClass == 'B') {
             price = 1000;
             }
        else if (roomClass == 'C') { 
            price = 300; 
        }
    } 
    else if (floorNum == 3) {
        if (roomClass == 'A') { 
            price = 2500; 
        }
        else if (roomClass == 'B') { 
            price = 1800;
         }
        else if (roomClass == 'C') {
             price = 1200; 
            }
    }
    if (price > 0) {
        cout << "Room charge: Rs. " << price << endl;
    } else {
        cout << "Invalid floor or class entered." << endl;
    }
    return 0;
}