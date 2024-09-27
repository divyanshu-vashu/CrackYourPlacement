//{ Driver Code Starts
#include <bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long>& a, long long n, long long m) {
    if (m == 0 || n == 0) {
        return 0;  // No students or no packets
    }
    
    if (n < m) {
        return -1;  // Not enough packets to distribute
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // Initialize the minimum difference as a large value
    long long minDiff = LLONG_MAX;
    
    // Find the minimum difference in all windows of size 'm'
    for (long long i = 0; i + m - 1 < n; i++) {
        long long diff = a[i + m - 1] - a[i]; // Difference between max and min in this window
        minDiff = min(minDiff, diff);
    }
    
    return minDiff;
}   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends