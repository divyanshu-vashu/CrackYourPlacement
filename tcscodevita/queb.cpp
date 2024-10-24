#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if X can be formed from substrings of Y and reversed Y
int minStringFactor(const string& X, const string& Y, int S, int R) {
    int n = X.length();
    int m = Y.length();
    
    // Reverse of Y to avoid recalculating it multiple times
    string Y_reverse = Y;
    reverse(Y_reverse.begin(), Y_reverse.end());
    
    // DP array to store the minimum string factor for each prefix of X
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0; // base case: empty string X can be formed without substrings

    // Preprocess the matching substrings using a sliding window approach
    for (int i = 0; i < n; ++i) {
        // Try to match substring from Y
        for (int j = 0; j < m; ++j) {
            if (Y[j] == X[i]) {
                int k = i, l = j;
                // Matching as long as characters match and within bounds
                while (k < n && l < m && X[k] == Y[l]) {
                    dp[k + 1] = min(dp[k + 1], dp[i] + S);
                    ++k; ++l;
                }
            }
        }
        
        // Try to match substring from reversed Y
        for (int j = 0; j < m; ++j) {
            if (Y_reverse[j] == X[i]) {
                int k = i, l = j;
                // Matching with reversed Y as long as characters match and within bounds
                while (k < n && l < m && X[k] == Y_reverse[l]) {
                    dp[k + 1] = min(dp[k + 1], dp[i] + R);
                    ++k; ++l;
                }
            }
        }
    }
    
    // If we couldn't form the entire string X
    if (dp[n] == 1e9) {
        return -1; // Impossible to form X from Y
    }
    
    return dp[n];
}

int main() {
    string X, Y;
    int S, R;
    
    // Input
    cin >> X;
    cin >> Y;
    cin >> S >> R;
    
    // Compute the result
    int result = minStringFactor(X, Y, S, R);
    
    
        cout << result << endl;
    
    
    return 0;
}
