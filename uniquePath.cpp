
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int f(int m, int n, vector<vector<int>> &dp){
        // Base case: If at the top-left corner (1,1), there's only one unique path.
        if(m == 1 && n == 1) return 1;
        // If we go out of bounds, return 0 since there's no valid path.
        if(m < 1 || n < 1) return 0;
        // If the value is already computed, return it.
        if(dp[m][n] != -1) return dp[m][n];
        // Recursively compute the number of paths by moving up and left.
        return dp[m][n] = f(m-1, n, dp) + f(m, n-1, dp);
    }

    int uniquePaths(int m, int n) {
        // dp is initialized with -1 to mark uncomputed states.
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // Start the recursion from (m,n).
        return f(m, n, dp);
    }
};
