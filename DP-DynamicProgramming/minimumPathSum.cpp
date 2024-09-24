#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
    int f(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        if (m == 0 && n == 0)
            return grid[0][0];
        if (m < 0 || n < 0)
            return INT_MAX;
        if (dp[m][n] != -1)
            return dp[m][n];

        int left = INT_MAX;
        int up = INT_MAX;

        if (n > 0)
            left = grid[m][n] + f(grid,m, n - 1,  dp);
        if (m > 0)
            up = grid[m][n] + f(grid,m - 1, n,  dp);

        return dp[m][n] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(grid, m - 1, n - 1, dp);
    }
};