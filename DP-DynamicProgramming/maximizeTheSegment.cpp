//{ Driver Code Starts
#include<bits/stdc++.h>
#include<iostream>
#include<vector>


using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int f(int n, int x, int y, int z,vector<int> &dp){
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        
        if(dp[n]!=-1) return dp[n];
        
        int a=f(n-x,x,y,z,dp)+1;
        int b=f(n-y,x,y,z,dp)+1;
        int c=f(n-z,x,y,z,dp)+1;
        
        return dp[n]=max(a,max(b,c));
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,-1);
        int ans=f(n,x,y,z,dp);
        if (ans < 0) return 0; 
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends