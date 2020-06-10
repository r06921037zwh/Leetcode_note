#include <stack>
#include <unordered_map>
class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return true;
        
        unordered_map<char, char> um;
        um[')'] = '(';
        um[']'] = '[';
        um['}'] = '{';
        
        stack<char> stk;
        for(auto c:s){
            if(c == '(' || c == '[' || c == '{'){
                stk.push(c);
            }else{
                if(stk.empty() || stk.top() != um[c]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};



// Another Method 
#include <stack>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return true;
        
        string left = "([{";
        string right = ")]}";
        
        stack<char> stk;
        for(auto c:s){
            if(left.find(c) != string::npos){
                stk.push(c);    
            }else{
                if(stk.empty() || stk.top() != left[right.find(c)]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
