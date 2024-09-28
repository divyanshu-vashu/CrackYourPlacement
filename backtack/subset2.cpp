#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    void f(int idx,int n,vector<int>& nums,vector<int> list,vector<vector<int>> &ans){
        ans.push_back(list);
        for(int i=idx;i<n;i++){
            //check for duplicate
            if(i!=idx && nums[i]==nums[i-1]) continue;

            list.push_back(nums[i]);
            f(i+1,n,nums,list,ans);
            list.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        f(0,n,nums,{},ans);
        return ans;
    }
};