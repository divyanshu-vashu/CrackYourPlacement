
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
using namespace std;

// class Solution {
// public:
//     bool ispalindrome(string s){
//         string newS=s;
//         reverse(newS.begin(),newS.end());
//         return s==newS;
//     }
//     bool validPalindrome(std::string s) {
//         int n = s.size(); // Length of the string
//         if (ispalindrome(s)) {
//             return true; // If the original string is already a palindrome
//         } else {
//             for (int i = 0; i < n; i++) {
//                 // Create a new string by removing the i-th character
//                 std::string subS = s.substr(0, i) + s.substr(i + 1);
//                 if (ispalindrome(subS)) {
//                     return true; // If removing the i-th character makes it a palindrome
//                 }
//             }
//         }
//         return false; // If no valid palindrome is found
//     }
// };

class Solution {
public:
    bool isPal(string s)
    {
        int n=s.length();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-1-i])
              return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        if(isPal(s))
          return true;

        string ans=s;
        int ind;
        int jnd;

        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-1-i])
             {
                ind=i;
                jnd=n-1-i;
                break;
             }
        }
        
        s.erase(ind,1);
        if(isPal(s))
           return true;
        s=ans;
        s.erase(jnd,1);
        if(isPal(s))
           return true;
        

        return false;
    }
};