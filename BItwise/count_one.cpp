#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countone(int n){
        int ans=0;
        while (n > 0) {
            if (n & 1) ans++;  // Check if the last bit is 1
            n = n >> 1;        // Shift `n` to the right by 1 bit to check the next bit
        }
        return ans;
    }
    int hammingWeight(int n) {
        // return __builtin_popcount(n);
        return countone(n);
    }
};