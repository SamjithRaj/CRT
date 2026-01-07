#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int, int>> fib;
    vector<pair<int, int>> prime;
    vector<pair<int, int>> fact;

    for(int i = 0; i<=9; i++){

        int f = 1;
        for(int j = 1; j <= i; j++){
            f *= j;
        }
        fact.push_back({i, f});

        if(i == 0){
            prime.push_back({0, 0});
        } else {
            int count = 0;
            for(int num = 2; ; num++){
                bool isPrime = true;
                for(int k = 2; k*k <= num; k++){
                    if(num % k == 0){
                        isPrime = false;
                        break;
                    }
                }
                if(isPrime){
                    count++;
                    if(count == i){
                        prime.push_back({i, num});
                        break;
                    }
                }
            }
        }

        if(i == 0){
            fib.push_back({0, 0});
        } else if(i == 1){
            fib.push_back({1, 0});
        } else if(i == 2){
            fib.push_back({2, 1});
        } else {
            int a = 0, b = 1, c;
            for(int m = 3; m <= i; m++){
                c = a + b;
                a = b;
                b = c;
            }
            fib.push_back({i, b});
        }
    }

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