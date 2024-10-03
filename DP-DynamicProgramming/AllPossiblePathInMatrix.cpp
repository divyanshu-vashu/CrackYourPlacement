//{ Driver Code Starts
// Initial Template for C++
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// } Driver Code Ends
// User function Template for C++

#define MODULO_EXP 1000000007

class Solution {
  public:
  
    void f(unordered_set<string> &s, int m, int n, string temp) {
        if (m == 0 && n == 0) {
            s.insert(temp);
            return;
        }
        
        if (m < 0 || n < 0) return;
        
        
        
        // Move to the right if possible
        if (m > 0) {
            f(s, m - 1, n, temp + 'R');
        }
        // Move down if possible
        if (n > 0) {
            f(s, m, n - 1, temp + 'D');
        }
        
        
    }
    
    long long int numberOfPaths(int n, int m, vector<vector<long long int>>& memo,unordered_set<string> &s,string temp)
{
    if (n == 1 || m == 1){
        
        auto result = s.insert(temp);
        if (result.second) {  // Only count if it was inserted (i.e., it's unique)
            return memo[n][m] = 1;
        }
    }
    // Add the element in the memo table
    // If it was not computed before
    if(m < 1 || n < 1 ) return 0;
    if (memo[n][m] == 0)
        memo[n][m] = numberOfPaths(n - 1, m, memo,s,temp+'R')
                     + numberOfPaths(n, m - 1, memo,s,temp+'D');

    return memo[n][m]%MODULO_EXP;
}

    long long int numberOfPaths(int m, int n) {
        
        unordered_set<string> s;
        // f(s, m-1, n-1, "");
        // return s.size();
        vector<vector<long long int >> memo(m+1,vector<long long int> (n+1,0));
        return numberOfPaths(m,n,memo,s,"");
        
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends