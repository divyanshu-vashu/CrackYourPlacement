//{ Driver Code Starts
// Initial template for C++
#include<iostream>
#include<vector>

using namespace std; 
#include <bits/stdc++.h>


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n = nums.size();
        vector<long long int> ans(n, 1);
        long long int mul = 1;
        int zeroCount = 0;
        
        // Calculate product of all elements, counting zeros
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                mul *= nums[i];
            } else {
                zeroCount++;
            }
        }
        
        // If more than 1 zero, all elements of ans should be 0
        if (zeroCount > 1) {
            return vector<long long int>(n, 0);
        }
        
        // Calculate the result
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans[i] = mul;  // If there's one zero, set product of non-zero elements at zero position
            } else if (zeroCount == 1) {
                ans[i] = 0;  // If there's one zero, set others to 0
            } else {
                ans[i] = mul / nums[i];  // Normal case
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends