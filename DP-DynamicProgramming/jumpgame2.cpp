#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
    vector<int> dp; // Memoization array
    
    int solve(int index, vector<int>& nums) {
        if (index >= nums.size() - 1) return 0; // Base case: if at or beyond the last index
        if (dp[index] != -1) return dp[index]; // Return cached result if available
        
        int ans = INT_MAX / 2; // Initialize to a large value (avoid overflow)
        
        for (int i = 1; i <= nums[index]; ++i) {
            if (index + i < nums.size() - 1 && dp[index + i] != -1) {
                ans = min(ans, 1 + dp[index + i]); // Use memoized result
            } else {
                ans = min(ans, 1 + solve(index + i, nums)); // Recur for the next index
            }
        }
        
        return dp[index] = ans; // Store result in dp array
    }
    
public:
    int jump(vector<int>& nums) {
        dp.assign(nums.size(), -1); // Initialize dp array with -1
        return solve(0, nums); // Start recursion from index 0
    }
};