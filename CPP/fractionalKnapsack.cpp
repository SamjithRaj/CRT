#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

void knapsack(int W) {
    int n; 
    cin >> n; 
    Item arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].value >>  arr[i].weight;
    }

    sort(arr, arr + n, compare);

    double finalValue = 0.0;

    for(int i = 0; i < n; i++){
        if(W == 0) break;
        if(arr[i].weight <= W){
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            W = 0;
        }
    }

    cout << fixed << setprecision(2) << finalValue << endl;
}
int main(){
    int size; 
    cin >> size;

    knapsack(size);
    return 0; 
}
