#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    void f(vector<int>& candidates, int target, int idx, vector<vector<int>>& ans, vector<int>& list) {
        if (target == 0) {
            ans.push_back(list);
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            if (candidates[i] > target) {
                break; 
            }
            
            list.push_back(candidates[i]);
            f(candidates, target - candidates[i], i + 1, ans, list); 
            list.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        
        // Sort the candidates to handle duplicates easily
        sort(candidates.begin(), candidates.end());
        
        f(candidates, target, 0, ans, list);
        return ans;
    }
};
