
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<utility> //pair

using namespace std;


// class Solution {
// public:
//     int m,n;
//     vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

//     bool ispossible(int &i,int &j,int &idx,string &word,vector<vector<char>>& board){
//         return i<m && j<n && i>=0 && j>=0 && board[i][j] != '0'&& word[idx] == board[i][j];
//     }

//     bool solve(vector<vector<char>>& board,int i,int j,int idx,string &word){
//         if(idx>=word.size()) return true;
//         char prev = board[i][j];
//         board[i][j] = '0';
//         for(int k=0;k<4;k++){
//             int newx = i+dir[k][0];
//             int newy = j+dir[k][1];
//             if(ispossible(newx,newy,idx,word,board)){
//                bool ans = solve(board,newx,newy,idx+1,word);
//                if(ans) return true;
//             }
//         }
//         board[i][j] = prev;
//         return false;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
       
//         bool ans = false;
//         m=board.size(),n=board[0].size();
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(board[i][j] == word[0]){
//                     ans = solve(board,i,j,1,word);
//                     if(ans) return ans;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
private:
    bool dfs(int i, int j, int m, int n, vector<vector<char>>& board, int ind, string& word) {
        if (ind == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[ind]) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';  // Mark as visited
        
        bool found = dfs(i+1, j, m, n, board, ind+1, word) ||
                     dfs(i-1, j, m, n, board, ind+1, word) ||
                     dfs(i, j+1, m, n, board, ind+1, word) ||
                     dfs(i, j-1, m, n, board, ind+1, word);
        
        board[i][j] = temp;  // Restore the original character
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, m, n, board, 0, word)) return true;
            }
        }
        return false;
    }
};