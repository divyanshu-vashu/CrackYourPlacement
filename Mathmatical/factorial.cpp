

#include<iostream>
#include <vector>


using namespace std;

const int MAXN = 18;
vector<long long> dp(MAXN + 1, -1);

// Initialize base cases
void initializeDP() {
    dp[0] = 1; // 0! = 1
    dp[1] = 1; // 1! = 1
}

// Function to compute factorial using memoization
long long f(int N, vector<long long>& dp) {
    // Base case
    if (N <= 1) return dp[N] = 1; // factorial(0) = 1 and factorial(1) = 1
    
    // Check if already computed
    if (dp[N] != -1) return dp[N];
    
    // Compute and store in dp
    dp[N] = N * f(N - 1, dp);
    return dp[N];
}

class Precompute {
public:
    Precompute() {
        // Initialize base cases
        initializeDP();
        // Precompute all factorials
        f(MAXN,dp);
    }
};

Precompute pre;

class Solution {
public:
    long long int factorial(int N) {
        // Ensure N is within bounds
        if (N < 0 || N > MAXN) {
            return -1; // or handle the error as appropriate
        }
        // Return the precomputed factorial
        return dp[N];
    }
};





//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends