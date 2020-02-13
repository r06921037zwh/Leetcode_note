/*
f[i] means minCut between interval [i, n-1]
f[i] = min{f[j+1] + 1}  i<=j<=n

p[i][j] = ture if interval [i, j] is a palindrome
p[i][j] = str[i] == str[j] && p[i+1][j-1]
*/

#include <string>
#include <vector>
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> f;
        vector<vector<int>> p;
        for(int i = 0; i <= n; i++){
            f.push_back(n-1-i); // worst cast: every word is a palindrome
        }
        for(int i = 0; i < n; i++){
            p.push_back(vector<int>(n, 0));
        }
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j - i < 2 || p[i+1][j-1])){
                    p[i][j] = 1;
                    f[i] = min(f[i], f[j+1] + 1);
                }
            }
        }
        return f[0];
    }
};
