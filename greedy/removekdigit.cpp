#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        
        // Step 1: Greedy approach using stack-like behavior
        for (char digit : num) {
            // While we can remove digits and the current digit is smaller than the last one in the result
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            // Append current digit to result
            result.push_back(digit);
        }
        
        // Step 2: If there are still digits to remove, remove from the end
        while (k > 0) {
            result.pop_back();
            k--;
        }

        // Step 3: Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        
        result = result.substr(i);  // Trim leading zeros

        // Step 4: Return the result, if empty return "0"
        return result.empty() ? "0" : result;
    }
};

