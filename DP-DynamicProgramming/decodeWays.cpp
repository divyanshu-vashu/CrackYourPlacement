#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    // bool validate(vector<int> &arr){
    //     int n=arr.size();
    //     for(int i=0;i<n;i++){
    //         if(!(arr[i]<=26 && arr[i]>=1)){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // int f(vector<int> arr,vector<vector<int>> &ans){
    //     if(validate(arr)){
    //         ans.push_back(arr);
    //     }
    //     vector<int > temp(arr.size()-1);
    //     for(int i=1;i<arr.size();i++){
    //         temp[i-1]=arr[i-1]+arr[i];
    //         f(temp,ans);
    //     }
    //     return ans.size();
    // }

    // int numDecodings(string s) {
    //     int n=s.length();
    //     vector<int> arr(n);
    //     vector<vector<int>> ans;

    //     for(int i=0;i<n;i++){
    //         arr[i]=s[i]-'0';
    //     }
        
    //     return f(arr,ans);

    // }
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