#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m ;i++) {
            for (int j = 0; j < n; j++) {
                int lu = (i - 1 >= 0 && j - 1 >= 0) ? board[i - 1][j - 1] : 0;
                int ld = (i + 1 < m && j + 1 < n) ? board[i + 1][j + 1] : 0;
                int ru = (i - 1 >= 0 && j + 1 < n) ? board[i-1][j + 1] : 0;
                int rd = (i + 1 < m && j - 1 >= 0) ? board[i + 1][j - 1] : 0;
                int u = (i - 1 >= 0) ? board[i - 1][j] : 0;
                int d = (i + 1 < m) ? board[i + 1][j] : 0;
                int l = (j - 1 >= 0) ? board[i][j - 1] : 0;
                int r = (j + 1 < n) ? board[i][j + 1] : 0; 
                int sum = lu + ld + ru + rd + u + d + l + r;
                if (board[i][j] == 1) {
                    if (sum < 2 || sum > 3) {
                        ans[i][j] = 0;
                    } else {
                        ans[i][j] = 1;
                    }
                }
                else {
                    if (sum == 3) {
                        ans[i][j] = 1;
                    } else {
                        ans[i][j] = 0;
                    }
                }
            }
        }
        
        board = ans;
    }
};