#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    
    int numDecodings(string s) {
        int n= s.length();
        if(n==0 || s[0]=='0') return 0;

        vector<int> dp(n+1,0);

        dp[0]=1;
        dp[1] = s[0]!='0' ? 1:0;

        for(int i=2;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];

            }
            int twodigit =(s[i-2]-'0')*10+(s[i-1]-'0');
            if(twodigit>=10 && twodigit <=26){
                dp[i]+=dp[i-2];
            }
        }

        return dp[n];

    }


};