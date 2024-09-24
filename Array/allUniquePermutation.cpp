//{ Driver Code Starts
//Initial Template for C++
#include<iostream>
#include<vector>

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void f(vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp, vector<bool> &used, int n) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            // Skip duplicate elements
            if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue;

            if (!used[i]) {
                used[i] = true;
                temp.push_back(arr[i]);

                f(ans, arr, temp, used, n);

                // Backtrack
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
        // Sort array to handle duplicates
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(n, false); // To track which elements are used

        f(ans, arr, temp, used, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends