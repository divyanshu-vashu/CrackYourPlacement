#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxans=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int ans=0;
        //     for(int j=i+1;j<n;j++){
        //         ans=prices[j]-prices[i];
        //         maxans=max(maxans,ans);
        //     }
        // }


        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int temp;
            if(prices[i]<mini) mini=prices[i];
            temp=prices[i]-mini;

            maxans=max(maxans,temp);
        }

        return maxans;
    }
};