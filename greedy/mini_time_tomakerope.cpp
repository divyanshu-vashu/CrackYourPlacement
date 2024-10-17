// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int n = colors.size();
//         int totalCost = 0;
        
//         for (int i = 0; i < n - 1; i++) {
//             // If consecutive balloons have the same color
//             if (colors[i] == colors[i + 1]) {
//                 // Add the smaller time to total cost
//                 if (neededTime[i] < neededTime[i + 1]) {
//                     totalCost += neededTime[i];
//                 } else {
//                     totalCost += neededTime[i + 1];
//                     // Move to the next pair of balloons
//                 }
//             }
//         }
        
//         return totalCost;
//     }
// };


#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int comparedTime = neededTime[0];

        for (int i = 1; i < colors.length(); i++) {
            if (colors[i] == colors[i - 1]) {
                res += min(neededTime[i], comparedTime);
                comparedTime = max(neededTime[i], comparedTime);
            } else {
                comparedTime = neededTime[i];
            }
        }

        return res;        
    }
};