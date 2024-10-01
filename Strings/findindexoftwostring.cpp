#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;



class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0; 
        int i;

        for (i = 0; i < haystack.length() && j < needle.length(); i++) {
            if (haystack[i] == needle[j]) {
                j++;
            } else {
                
                i = i - j;
                j = 0;
            }

           
            if (j == needle.size()) {
                return i - j + 1;
            }
        }

        return -1;
    }
};


/* 

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i <= n - m; i++) { // Changed loop condition
            int j;
            for (j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) // Compare characters from haystack and needle
                    break;
            }
            if (j == m) { // If all characters in needle match
                return i;
            }
        }
        return -1;
    }
};
*/