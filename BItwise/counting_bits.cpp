#include<iostream>
#include<vector>
using namespace std;
// class Solution {
// public:
//     string convertBinary(int n) {
//         if (n == 0) return "0";
//         string b = "";
//         while (n > 0) {
//             b = (n % 2 == 0 ? "0" : "1") + b;
//             n /= 2;
//         }
//         return b;
//     }

//     int countOne(string s) {
//         int c = 0;
//         for (char ch : s) {
//             if (ch == '1') c++;
//         }
//         return c;
//     }

//     vector<int> countBits(int n) {
//         vector<int> ans(n + 1);
//         for (int i = 0; i <= n; ++i) {
//             string s = convertBinary(i);
//             ans[i] = countOne(s);
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> dp(n+1, -1);
//         dp[0] = 0;
//         for(int i=1; i<=n; i++){
//             if(i%2) dp[i] = dp[i/2] + 1;
//             else dp[i] = dp[i/2];
//         }
//         return dp;
//     }
// };

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int bits=__builtin_popcount(i);
            ans.push_back(bits);
        }

        return ans;
    }
};
