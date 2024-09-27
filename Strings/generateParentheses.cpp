
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;



class Solution {
public:
    void backtrack(int open_count, int close_count, int n, string current, vector<string> &result) {
        // Base case: if the current string has 2*n characters, it's a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have '(' to add
        if (open_count < n) {
            backtrack(open_count + 1, close_count, n, current + '(', result);
        }

        // Add ')' if we have more '(' than ')'
        if (close_count < open_count) {
            backtrack(open_count, close_count + 1, n, current + ')', result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, n, "", result);  // Initialize the recursive function
        return result;
    }
};
