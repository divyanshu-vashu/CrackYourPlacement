#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Function to count the number of set bits in an integer
    int countBits(int a) {
        return __builtin_popcount(a);
    }

    // Function to sort by number of bits
    vector<int> sortByBits(vector<int>& arr) {
        auto lamda = [this](int &a, int &b) {  // Capturing 'this' to access class members
            int ca = countBits(a);
            int cb = countBits(b);

            // If both have the same number of bits, sort by value
            if (ca == cb) return a < b;
            return ca < cb;
        };

        // Sorting the array using the lambda comparator
        sort(arr.begin(), arr.end(), lamda);
        return arr;
    }
};
