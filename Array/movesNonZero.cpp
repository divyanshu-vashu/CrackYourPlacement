
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<utility> //pair

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j = 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                
                nums[j]=nums[i];
                j++;
            }
        }
        for (int i = j; i < nums.size(); i++) {
            nums[i] = 0;
        }

        
        
    }
};