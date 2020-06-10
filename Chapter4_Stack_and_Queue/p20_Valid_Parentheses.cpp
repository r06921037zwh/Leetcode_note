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
