#include <iostream>
#include <vector>
#include <numeric> // for std::gcd and std::accumulate
#include <algorithm> // for std::max

class Solution {
public:
    // Corrected gcd_of_array function
    long long gcd_of_array(const std::vector<int>& arr) {
        return std::accumulate(arr.begin(), arr.end(), arr[0], std::gcd<int, int>);
    }

    // Using long long to avoid overflow in lcm calculations
    static long long lcm(long long a, long long b) {
        return (a * b) / std::gcd(a, b);
    }

    // Changed return type and initialization of lcm_of_array to long long
    long long lcm_of_array(const std::vector<int>& arr) {
        return std::accumulate(arr.begin(), arr.end(), 1LL, Solution::lcm);
    }
    
    std::vector<int> exclude_ith_element(const std::vector<int>& arr, int index) {
        std::vector<int> new_arr;
        for (int i = 0; i < arr.size(); i++) {
            if (i != index) { // Skip the i-th element
                new_arr.push_back(arr[i]);
            }
        }
        return new_arr;
    }

    long long maxScore(std::vector<int>& nums) {
        if (nums.size() == 1) return static_cast<long long>(nums[0]) * nums[0];

        long long maxGcd = gcd_of_array(nums);
        long long maxLcm = lcm_of_array(nums);
        long long maxAns = maxGcd * maxLcm;

        for (int i = 0; i < nums.size(); i++) {
            std::vector<int> newarr = exclude_ith_element(nums, i);
            long long gcd = gcd_of_array(newarr);
            long long v_lcm = lcm_of_array(newarr);
            long long ans = gcd * v_lcm;
            if (ans > maxAns) {
                maxAns = ans;
            }
        }
        return maxAns;
    }
};
