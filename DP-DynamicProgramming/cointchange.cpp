#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
    int f(vector<int>& coins,int n, int amount,vector<int> &dp){
        if(amount==0) return 0;

        if(amount<0) return INT_MAX;

        if(dp[amount]!=-1) return dp[amount];
        int a=INT_MAX;
        for(int i=0;i<n;i++){
           int res = f(coins, n,amount - coins[i], dp);
            if (res != INT_MAX) {  
                a = min(a, res + 1);  
            }
        }
        return dp[amount]=a;

    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();

        vector<int> dp (amount+1,-1);
        int result = f(coins,n,amount,dp);
        return (result == INT_MAX) ? -1 : result;
        
    }
};