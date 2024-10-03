
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // vector<bool> check(n,vector<bool>(m,false));
        unordered_set<int> zerolist;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) zerolist.insert(i);zerolist.insert(j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(zerolist.find(i)!=zerolist.end() || zerolist.find(i)!=zerolist.end()){
                    matrix[i][j]==0;
                }
            }
        }


    }
};

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Sets to keep track of which rows and columns need to be zeroed
        unordered_set<int> zeroRows;
        unordered_set<int> zeroCols;

        // Identify all the rows and columns that need to be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        // Set the rows to zero
        for (int i = 0; i < n; i++) {
            if (zeroRows.find(i) != zeroRows.end()) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set the columns to zero
        for (int j = 0; j < m; j++) {
            if (zeroCols.find(j) != zeroCols.end()) {
                for (int i = 0; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
