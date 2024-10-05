#include <vector>
#include <unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n= nums.size();
        m[0]=1;
        int presum=0,cnt=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];

            int rem= presum-k;
            if(m.find(rem)!=m.end()) cnt+=m[rem];

            m[presum]++;

        }
        return cnt;
    }
};

/*

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            int sum=0;
            
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k) c++;;
            }
        }
        return c;
    }
};

*/