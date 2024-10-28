

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int leftsmall[n], rightsmall[n];
        // leftsmall ;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            if (st.empty())
                leftsmall[i] = 0;
            else
                leftsmall[i] = st.top() + 1;
            st.push(i);
        }
        // clear the stack to be re-used
        while (!st.empty())
            st.pop();

        // right small
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && height[st.top()] >= height[i])
                st.pop();

            if (st.empty())
                rightsmall[i] = n - 1;
            else
                rightsmall[i] = st.top() - 1;

            st.push(i);
        }
        // calculating area ;
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            int width = rightsmall[i] - leftsmall[i] + 1;
            int side = min(width, height[i]);  // Square constraint
            maxA = max(maxA, side * side);     // Area of the square
        }
        return maxA;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            int area=largestRectangleArea(height);
            maxarea=max(maxarea,area);

        }
        return maxarea;
    }
};