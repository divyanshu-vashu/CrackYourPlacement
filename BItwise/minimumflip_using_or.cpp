#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while (a > 0 || b > 0 || c > 0) {  // Check until all bits in a, b, and c are processed
            int bitA = a & 1;  // Extract the lowest bit of a
            int bitB = b & 1;  // Extract the lowest bit of b
            int bitC = c & 1;  // Extract the lowest bit of c

            if (bitC == 1) {
                // To match c = 1, either bitA or bitB must be 1
                if (bitA == 0 && bitB == 0) {
                    ans++;  // We need one flip to make either bitA or bitB 1
                }
            } else {
                // To match c = 0, both bitA and bitB must be 0
                if (bitA == 1 && bitB == 1) {
                    ans += 2;  // Both a and b bits need to be flipped
                } else if (bitA == 1 || bitB == 1) {
                    ans++;  // One flip is needed
                }
            }

            // Right shift all the numbers to process the next bit
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};


class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = (a | b) ^ c;
        return __builtin_popcount(result) + __builtin_popcount((a & b) & (result));
    }
};