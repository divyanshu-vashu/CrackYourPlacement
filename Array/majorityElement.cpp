#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        for(auto it:mpp){
            if(it.second>n/2) return it.first;
        }
        return 0;
        // int count = 0;
        // int maxcount = 0;
        // for(int i=0;i<nums.size();i++){
        //     if(count == 0){
        //         maxcount = nums[i];
        //         count++;
        //     }else if(maxcount == nums[i]){
        //         count++;
        //     }else{
        //         count--;
        //     }
        // }
        // return maxcount;
    }
};