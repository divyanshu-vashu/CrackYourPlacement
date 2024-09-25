#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int f(vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if (matrix[i][j] == 0) dp[i][j] = 0;
                else{
                if(dp[i-1][j]>0 && dp[i-1][j-1]>0 &&dp[i][j-1]>0 ){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=dp[i][j];
            }
        }

        return ans;
        
    }
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp;
        dp=matrix;
        return f(matrix,dp);
        
        }
};