
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<utility>

using namespace std;
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        int n=points.size();

        // method 1 

        // for(int i=0;i<=n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(abs(points[i][0]-points[j][0])<= k){
        //             int temp = points[i][1]+points[j][1]+abs(points[i][0]-points[j][0]);
        //             ans=max(temp,ans);
        //         }
                
        //     }
        // }


        // method2 : 
        priority_queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            while((!q.empty())&&points[i][0]-q.top().second>k) q.pop();
            if(!q.empty()){
                ans=max(ans,points[i][0]+points[i][1]+q.top().first);
            }
            q.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;
    }
};