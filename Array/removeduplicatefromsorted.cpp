#include<iostream>
#include<vector>

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;  // Handle edge case of empty array

        int j = 0;  // Pointer for placing non-duplicate elements
        for (int i = 1; i <nums.size(); i++) {
            if (nums[i] != nums[j]) {  // If current element is not duplicate
                j++;                    // Move the placement pointer
                nums[j] = nums[i];      // Place the non-duplicate element
            }
        }
        
        nums.resize(j + 1);
        return j+1;
    }
};