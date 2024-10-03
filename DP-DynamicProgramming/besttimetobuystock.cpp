#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int memoization(int index, int& n, vector<int>& prices,
                    vector<vector<int>>& dp, int buy) {
        if (index == n) {
            return 0;
        }
        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }
        int profit = 0;
        if (buy) {
            profit =
                max((memoization(index + 1, n, prices, dp, 0) - prices[index]),
                    memoization(index + 1, n, prices, dp, 1));
        } else {
            profit =
                max((memoization(index + 1, n, prices, dp, 1) + prices[index]),
                    memoization(index + 1, n, prices, dp, 0));
        }
        return dp[index][buy] = profit;
    }
    int tabulation(int& n, vector<int>& prices) {
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            int profit = 0;
            for (int buy = 0; buy <= 1; buy++) 
            {
                cout << buy << " ";
                if(buy)
                {
                    profit = max((dp[i + 1][0] - prices[i]),dp[i + 1][1]);
                } 
                else
                {
                    profit = max((dp[i + 1][1] + prices[i]), dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int spaceOptimization(int& n, vector<int>& prices) {
        vector<int> prev(2, 0);
        vector<int> curr(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int profit = 0;
            for (int buy = 0; buy <= 1; buy++) 
            {
                if(buy)
                {
                    profit = max((prev[0] - prices[i]),prev[1]);
                } 
                else
                {
                    profit = max((prev[1] + prices[i]), prev[0]);
                }
                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        
        // return memoization(0, n, prices, dp, 1);
        return spaceOptimization(n, prices);
        // return max(memoization(0,n,prices,dp,1),memoization(0,n,prices,dp,0));    
        }
};