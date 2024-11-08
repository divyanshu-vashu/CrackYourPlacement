
#include <iostream>
#include<vector>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;




class Solution {

  public:
    

    
    int solve(std::vector<int>& coins, int n, int sum, std::vector<int> &dp) {
        // Base case: if sum is 0, no coins are needed
        if (sum == 0) {
            return 0;
        }
        
        // If sum goes below 0, this path is invalid
        if (sum < 0) {
            return INT_MAX;
        }

        // If we have already computed the answer for this sum, return it
        if (dp[sum] != -1) {
            return dp[sum];
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int result = solve(coins, n, sum - coins[i], dp);
            if (result != INT_MAX) {  // update only if a valid solution was found
                ans = std::min(ans, result + 1); // +1 to include the current coin
            }
        }

        // Store the result in dp array for the current sum
        dp[sum] = ans;
        return dp[sum];
    }

    int minCoins(std::vector<int>& coins, int sum) {
        int n = coins.size();
        
        // Handle cases where no solution is possible
        if (sum == 0) return 0;
        
        // Initialize DP array with a large number (indicating no solution yet)
        std::vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0; // Base case: 0 coins are needed to make sum of 0
        
        // Bottom-up DP approach
        for (int i = 1; i <= sum; i++) {
            for (int coin : coins) {
                if (coin == 0) continue;  // Skip zero-value coins to prevent infinite loop
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[sum] is still INT_MAX, it means sum cannot be formed
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    } 
};