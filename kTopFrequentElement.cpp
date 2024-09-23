#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n= nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        // vector<pair<int,int>> v;
        // for(auto m:mp) v.push_back({m.second,m.first});

        // sort(v.rbegin(),v.rend());
        // 
        // for(int i=0;i<v.size() && k!=0;i++){
        //     ans.push_back(v[i].second);
        //     k--;
        // }
        // return ans;
        priority_queue<pair<int,int>> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        while(k--){
            int top=pq.top().second;
            ans.push_back(top);
            pq.pop();

        }


return ans;


    }
};