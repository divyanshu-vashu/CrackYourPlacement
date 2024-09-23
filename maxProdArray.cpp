#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0) return 0; 
       
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];
        
        for (int i = 1; i < n; i++) {
            
            int tempMax = maxProd;
            
            maxProd = max(nums[i], max(nums[i] * maxProd, nums[i] * minProd));
            minProd = min(nums[i], min(nums[i] * tempMax, nums[i] * minProd));
            ans = max(ans, maxProd);
        }
        
        return ans;
    }
};
