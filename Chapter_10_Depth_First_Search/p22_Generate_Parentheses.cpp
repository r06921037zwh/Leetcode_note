#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        generate(n, n, "", results);
        return results;
    }
    
    /*
        left: remaining number of left parentheses
        right: remaining number of right parentheses
        item: current used pattern
        results: final results
    */
    void generate(int left, int right, string item, vector<string>& results){
        if(left == 0 && right == 0){
            results.push_back(item);
            return;
        }
        // if remaining left parentheses is greater than 0, can keep putting it
        if(left > 0){  
            generate(left-1, right, item+"(", results);
        }
        // if remaining right parentheses is more than left, can keep putting it
        if(right > left){
            generate(left, right-1, item+")", results);
        }
    }
};
