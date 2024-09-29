
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<utility> //pair

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // Pointer for the last element in the valid part of nums1
        int j = n - 1;  // Pointer for the last element in nums2
        int k = m + n - 1;  // Pointer for the last position in nums1
        
        // Merge in reverse order
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        // If there are remaining elements in nums2, fill them in nums1
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int run=m+n;
//         int j=0,k=0;
//         for(int i=0;i<run && j<n;i++){
//             if(nums1[i]>nums2[j] || nums1[i]==0){
//                 swap(nums1[i],nums1[m+k]);
//                 nums1[i]=nums2[j];
//                 j++;k++;
//             }
//         }
//         sort(nums1.begin(),nums1.end());
//     }
// };
