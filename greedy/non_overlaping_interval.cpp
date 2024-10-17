#include<iostream>
#include<vector>

using namespace std; 
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = intervals.size();
        int ans = 0;
        int lastEnd = intervals[0][1]; // End time of the last added interval

        for (int i = 1; i < n; ++i) {
            // If the current interval starts before the last added one ends, it's overlapping
            if (intervals[i][0] < lastEnd) {
                ans++;
            } else {
                // Update the end time to the current non-overlapping interval
                lastEnd = intervals[i][1];
            }
        }
        return ans;
    }
};
