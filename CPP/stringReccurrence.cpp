        #include<bits/stdc++.h>
        using namespace std; 

        int stringReoccurrence(int i, int j, string &s1, string &s2, vector<vector<int>> &memo){
            if(j == 0){
                return 1;
            }
            if(i == 0){
                return 0;
            }
            
            if(memo[i][j] != -1){
                return memo[i][j];
            }

            int cnt = stringReoccurrence(i - 1, j, s1, s2, memo);
            if(s1[i - 1] == s2[j - 1]){
                cnt += stringReoccurrence(i - 1, j - 1, s1, s2, memo);
            }
            
            return memo[i][j] = cnt;
        }

        int main(){
            string s1, s2;
            cin >> s1 >> s2;
            vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, -1));
            cout << stringReoccurrence(s1.length(), s2.length(), s1, s2, memo) << endl;
            
            return 0;
        }