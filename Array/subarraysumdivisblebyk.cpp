

#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;  // Initialize with remainder 0, to count subarrays starting from index 0.
        
        int sum = 0, cnt = 0;
        
        for (int num : nums) {
            sum += num;
            
            // Calculate remainder of the current sum.
            int remainder = sum % k;
            
            // Adjust remainder to be positive (if negative).
            if (remainder < 0) {
                remainder += k;
            }
            
            // If the remainder has been seen before, add the frequency to the count.
            if (remainderCount.find(remainder) != remainderCount.end()) {
                cnt += remainderCount[remainder];
            }
            
            // Increment the count of this remainder.
            remainderCount[remainder]++;
        }
        
        return cnt;
    }
};
