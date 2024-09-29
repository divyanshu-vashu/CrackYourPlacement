
#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        
        while (columnNumber > 0) {
            
            columnNumber--;
            
            char currentChar = static_cast<char>('A' + (columnNumber % 26));
            
            ans = currentChar + ans;
            
            columnNumber /= 26;
        }
        
        return ans;
    }
};
