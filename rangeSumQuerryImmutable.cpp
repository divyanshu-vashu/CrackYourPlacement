#include<iostream>

#include<vector>
using namespace std;


class NumArray {
public:
    vector<int> ans;
    NumArray(vector<int>& nums) {
        
        int n=nums.size();
        
        ans.resize(n);
        int c=0;
        for(int i=0;i<n;i++){
            c+=nums[i];
            ans[i]=c;
        }
    }
    
    int sumRange(int left, int right) {
        int rightsum = ans[right];
        int leftsum = (left == 0) ? 0 : ans[left - 1];
        return rightsum-leftsum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */