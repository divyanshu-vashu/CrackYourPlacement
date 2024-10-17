#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int startStation = 0, tank = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            
            // If at any point, the tank is negative, we can't start from previous stations.
            if (tank < 0) {
                startStation = i + 1;  // Start from the next station.
                tank = 0;  // Reset the tank.
            }
        }
        
        // If total gas is less than total cost, no solution is possible.
        return totalGas >= totalCost ? startStation : -1;
    }
};
