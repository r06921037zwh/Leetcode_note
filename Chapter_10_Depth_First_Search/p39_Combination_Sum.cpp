#include <vector>
#include <algorithm> // sort
#include <numeric>   // accumulate
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            result.push_back(temp);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++){
            if(sum+candidates[i] <= target){
                temp.push_back(candidates[i]);
                dfs(result, temp, candidates, target, i);
                temp.pop_back();
            }
        }
    }
};
