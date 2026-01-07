#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int, int>> fib = { {0, 0}, {1,1}, {2,1}, {3,2}, {4,3}, {5,5}, {6,8}, {7,13}, {8,21}, {9,34}};
    vector<pair<int, int>> prime = { {0,0}, {1,2}, {2,3}, {3,5}, {4,7}, {5,11}, {6,13}, {7,17}, {8,19}, {9,23}};
    vector<pair<int, int>> fact = { {0,1}, {1,1}, {2,2}, {3,6}, {4,24}, {5,120}, {6,720}, {7,5040}, {8,40320}, {9,362880}};

    int n; 
    cin >> n; 
    int cnt = log10(n) + 1;
    long long factSum = 0;
    int primeSum = 0;
    int fibSum = 0;

    for(int i = 0; i<cnt; i++){
        int digit = n % 10;
        n /= 10;

        for(auto p : fact){
            if(p.first == digit){
                factSum += p.second;
                break;
            }
        }

        for(auto p : prime){
            if(p.first == digit){
                primeSum += p.second;
                break;
            }
        }

        for(auto p : fib){
            if(p.first == digit){
                fibSum += p.second;
                break;
            }
        }
    }
    cout << factSum << endl;
    cout << primeSum << endl;
    cout << fibSum << endl;
    return 0;

}