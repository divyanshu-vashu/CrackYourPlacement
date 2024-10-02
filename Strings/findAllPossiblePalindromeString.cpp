//{ Driver Code Starts
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>



using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool checkPalindrome(string& s)
    {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void Partition(vector<vector<string> >& res, string& s,
                   int idx, vector<string>& curr)
    {
        
        if (idx == s.size()) {
            res.push_back(curr);
            return;
        }
        // Stores the current substring.
        string t;
        for (int i = idx; i < s.size(); i++) {
            t.push_back(s[i]);

            // Check whether the string is palindrome is
            // not.
            if (checkPalindrome(t)) {

                // Adds the string to current list
                curr.push_back(t);

                // Recursive call for the remaining string
                Partition(res, s, i + 1, curr);

                
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        
        vector<vector<string>> res;
        vector<string> curr;
        Partition(res,s,0,curr);
        return res;
            
        }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends