/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

// Method 1: Time complexity O(2^n), Space Complexity O(n)
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        dfs(result, temp, s, 0);
        return result;
    }
    
    // search the string partition starting with s[start] 
    void dfs(vector<vector<string>>& result, vector<string>& temp, string& s, int start){
        // Base condition: if the start goes to the end, then store the current result and return
        if (start == s.size()){
            result.push_back(temp);
            return;
        }
        
        // Backtracking
        for(int i=start; i<s.size(); i++){
            if(isPalindrome(s, start, i)){                   // check whether s[start:i] is a palindrome
                temp.push_back(s.substr(start, i-start+1));  // if yes, then store the s[start:i] into current partition and search s[i+1]
                dfs(result, temp, s, i+1);
                temp.pop_back();                             // pop back the s[start:i], ready for search from s[start+1]
            }
        }
    }
    
    // judge whether string s[start:end] is a palindrome
    bool isPalindrome(string& s, int start, int end){
        while(start<=end && s[start]==s[end]){
            start++;
            end--;
        }
        return start>=end;
    }
};
