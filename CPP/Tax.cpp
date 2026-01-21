#include<bits/stdc++.h>
using namespace std;

int main(){
    int waterCons, tax; 
    if(waterCons <= 60){
        tax = 0;
    }
    else if(waterCons > 60 && waterCons <= 120){
        tax = 300;
    }
    else if(waterCons > 120 && waterCons <= 220){
        tax = 500;
    }
     else if(waterCons > 220 && waterCons <= 350){
        tax = 800;
    }
    else if(waterCons > 350){ 
        tax = 1200;
    }
    cout << "Water Consumed (in gallons): " << waterCons << endl;
    cout << "Tax: " << tax << endl;
    return 0;

}