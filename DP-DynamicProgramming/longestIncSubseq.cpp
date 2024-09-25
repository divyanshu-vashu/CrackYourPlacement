#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n=nums.size();
        vector<int> dp(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    
                }
            }
        }
        
       
        // for(int i=n-1;i>=0;i--){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[j]>nums[i]){
        //             dp[i]=max(dp[i],dp[j]+1);
                    
        //         }
        //     }
        // }
        return *max_element(dp.begin(),dp.end());


    }
};