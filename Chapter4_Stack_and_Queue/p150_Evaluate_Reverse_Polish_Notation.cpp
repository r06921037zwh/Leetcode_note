#include <stack>
#include <string>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0) return 0;
        
        stack<int> nums;
        const string op = "+-*/";
        int a, b;
        for(auto token: tokens){
            if(op.find(token) != string::npos){
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                
                if(token == "+") nums.push(a+b);
                else if(token == "-") nums.push(a-b);
                else if(token == "*") nums.push(a*b);
                else nums.push(a/b);
            }else{
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};
