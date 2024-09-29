#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int numleft=target-num;
            if(mp.find(numleft) != mp.end()){
                return {mp[numleft],i};
            }
            mp[num]=i;
        }
        return ans;
    }
};