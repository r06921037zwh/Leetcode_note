#include <vector>
#include <algorithm> // sort
#include <numeric>   // accumulate
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        
        sort(candidates.begin(), candidates.end());  //make sure the numbers are in increasing order
        dfs(result, temp, candidates, target, 0);
        return result;
    }
    /*
        (1) result : store all possible combinations
        (2) temp : store current solution
        (3) candidates : input numbers
        (4) target : input target
        (5) start : from which index to start searching. Search should be in increasing order to avoid repeat results , like [2,2,3] and [2,3,2]
    */
    void dfs(vector<vector<int>>& result, vector<int>& temp, vector<int>& candidates, int target, int start){
        int sum = accumulate(temp.begin(), temp.end(), 0);
        if(sum == target){
            int flag = false;    //Use a flag to record whether the current one is repeated 
            for(int i=0; i<result.size(); i++){
                if(result[i] == temp)
                    flag = true;
            }
            if(!flag){
                result.push_back(temp);
                return;
            } 
        }
        
        int previous = -1;                         // Use previous to record the current put index 
        for(int i=start; i<candidates.size(); i++){
            if(previous == i) continue;            // if using the same index, then pass
            
            if(sum+candidates[i] <= target){
                previous = i;
                temp.push_back(candidates[i]);
                dfs(result, temp, candidates, target, i+1);
                temp.pop_back();
            }
        }
    }
};
