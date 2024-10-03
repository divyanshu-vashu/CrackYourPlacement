
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int count = 0;
        unordered_map<long long,int> hash_map;
        long long prefixSum = 0;

        for(int i=0;i<nums.size();i++) {
            prefixSum += nums[i];

            if(prefixSum == k) {
                count++;
            }
            
            long long rem = prefixSum - k;
            if(hash_map.find(rem) != hash_map.end()) {
                count += hash_map[rem];
            }

            if(hash_map.find(prefixSum) != hash_map.end()) {
                hash_map[prefixSum]++;
            } else {
                hash_map[prefixSum] = 1; 
            }
        }

        return count;
    }
};