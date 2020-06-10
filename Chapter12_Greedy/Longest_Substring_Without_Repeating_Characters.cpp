#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map <char, int> um;
        int maxLen = 0;
        int start = 0;
        for(int i=0; i<n; i++){
            if(um.find(s[i]) != um.end()){
                maxLen = max(maxLen, i-start);
                start = max(start, um[s[i]]+1);
            }
            um[s[i]] = i;
        }
        maxLen = max(maxLen, n-start);
        return maxLen;
    }
};
