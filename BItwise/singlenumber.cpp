#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<32;k++){
            int countOne=0,countZero=0;
            int temp=(1<<k);
            for(int &num:nums){
                
                if((num&temp)==0) countZero++;
                else countOne++;
            }
            if(countOne % 3 == 1) {
                result = (result | temp);
            }
        }
        return result;
    }
};