
#include<iostream>
#include<vector>

using namespace std; 
// class Solution {
// public:
//     void f(vector<vector<int>>&ans,int n,int k,int idx,vector<int> list){
//         if(list.size()==k){
//             ans.push_back(list);
//         }
//         if(list.size()>k){
//             return ;
//         }
//         for(int i=0;i<n;i++){
//             // skip duplicate;
//             if (i > idx && i==idx ) {
//                 continue;
//             }

//             list.push_back(i);
//             f(ans,n,k,i+1,list);
//             list.pop_back();
//         }
//     }
//     vector<vector<int>> combine(int n, int k) {
//         vector<vector<int>> ans;
//         f(ans,n,k,0,{});
//         return ans;
//     }
// };

class Solution {
public:
    void f(vector<vector<int>>& ans, int n, int k, int idx, vector<int>& list) {
        // Base case: if the list size is equal to k, store the combination
        if(list.size() == k) {
            ans.push_back(list);
            return;
        }
        
        // Try to form combinations by adding elements
        for(int i = idx; i <= n; i++) {
            // Add the current element
            list.push_back(i);
            
            // Recursive call with the next index
            f(ans, n, k, i + 1, list);
            
            // Backtrack to remove the last element and explore new possibilities
            list.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> list;
        f(ans, n, k, 1, list); // Start the recursion from 1 since we want combinations from [1, n]
        return ans;
    }
};
