#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;     // store all possible IPs
        vector<string> temp;       // store current processing result
        dfs(result, temp, s, 0);
        return result;
    }
    
    /*
      (1) result: store all possible IPs
      (2) temp: store current processing result
      (3) s: input string
      (4) start: current processing index
    */
    void dfs(vector<string>& result, vector<string>& temp, string& s, int start){
        if(start == s.size() && temp.size() == 4){     // Base condition : find one solution 
            string ip = temp[0] + '.' + temp[1] + '.' + temp[2] + '.' + temp[3];
            result.push_back(ip);
            return;
        }
        
        if(s.size()-start > 3*(4-temp.size()))         // Base condition : pruning
            return;
        if(s.size()-start < 4-temp.size())             // Base condition : pruning
            return;
        
        int num = 0;
        for(int i=start; i<start+3; i++){
            num = num * 10 + (s[i] - '0');
            
            if(num < 0 || num > 255) continue;         // pruning
            
            temp.push_back(s.substr(start, i-start+1));
            dfs(result, temp, s, i+1);
            temp.pop_back();
            
            if(num == 0) break;                        // allow single '0', not allow '0' as prefix
        }
    }
};
