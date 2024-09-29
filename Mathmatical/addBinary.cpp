
#include<iostream>
#include<vector>

using namespace std; 


// class Solution {
// public:
//     int convDecimal(string s) {
//     int sum = 0;
//     int n = s.length();
//     int p = 0;
//     for (int i = n - 1; i >= 0; i--) {
//         sum += (s[i] - '0') * pow(2, p++); // Corrected to use base 2
//     }
//     return sum;
// }


//     string convBinary(int a) {
//     string s = "";
//     if (a == 0) return "0";  // Edge case for 0
//     while (a > 0) {
//         if (a % 2 == 0)
//             s = '0' + s;  // Prepend to build the binary string
//         else
//             s = '1' + s;
//         a /= 2;  // Update a for the next iteration
//     }
//     return s;
// }

//     string addBinary(string a, string b) {
//         int ans=convDecimal(a)+convDecimal(b);
//         return convBinary(ans);
//     }
// };


class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};