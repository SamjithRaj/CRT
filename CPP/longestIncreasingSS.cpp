#include<bits/stdc++.h>
using namespace std; 

int longestIncreasingSubsequence(vector<int> &ls){
    int n = ls.size();
    vector<int> sub; 
    if(n == 0) return 0;
    sub.push_back(ls[0]);
    for(int i = 1; i<n; i++){
        if(ls[i] > sub.back()){
            sub.push_back(ls[i]);
        } else {
            // Find first element >= ls[i] and replace it
            for(int j = 0; j < sub.size(); j++){
                if(sub[j] >= ls[i]){
                    sub[j] = ls[i];
                    break;
                }
            }
        }
    }
    for(auto it : sub){
        cout << it << " ";
    }
    cout << endl;
    return sub.size();

}

int main(){
    int n; 
    cin >> n; 
    vector<int> ls(n);
    for(int i = 0; i<n; i++){
        cin >> ls[i];
    }
    cout << longestIncreasingSubsequence(ls) << endl;
    return 0;
}