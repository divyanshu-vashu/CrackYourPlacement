
#include<iostream>
using namespace std;

#define m 1000000007

class Solution {
public:
    string fun(string s) {
        string news1 = "";
        for (auto c : s) {
            if (c == 'z') {
                news1 += "ab";
            } else {
                int k = static_cast<int>(c);
                k++;
                news1 += static_cast<char>(k);
            }
        }
        return news1;
    }

    int lengthAfterTransformations(string s, int t) {
        string s1 = s;
        // while (t--) {
        //     s1 = fun(s1);
        // }
        // return s1.length() % m;
        const int MOD = 1e9 + 7;
        vector<long long> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (int j = 0; j < t; j++) {
            vector<long long> tmp(26, 0);
            for (int i = 0; i < 26; i++) {
                if (i == 25) {
                    tmp[0] = (tmp[0] + cnt[i]) % MOD;
                    tmp[1] = (tmp[1] + cnt[i]) % MOD;
                } else {
                    tmp[i + 1] = (tmp[i + 1] + cnt[i]) % MOD;
                }
            }
            cnt = tmp;
        }

        long long len = 0;
        for (long long c : cnt) {
            len = (len + c) % MOD;
        }

        return len;

        
    }
};
