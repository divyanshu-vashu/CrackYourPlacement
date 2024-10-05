#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;
        
        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totalSum += cardPoints[i];
        }

        // If we are taking all cards, return the total sum
        if (k == n) return totalSum;
        
        // Find the minimum sum of the subarray of size n - k
        int windowSize = n - k;
        int windowSum = 0;
        
        // Sum of the first window of size n - k
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }
        
        int minWindowSum = windowSum;
        
        // Slide the window and find the minimum sum
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }
        
        // The maximum score is the total sum minus the minimum window sum
        return totalSum - minWindowSum;
    }
};
