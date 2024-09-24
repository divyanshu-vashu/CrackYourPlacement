
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {


public:
    void merge(vector<int>& nums, int low, int high, int& reversePairsCount, int mid){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }
    void mergeSort(vector<int>& nums,int start,int end,int &ans){
        
        if(start>=end){
            return ;
        }
        int mid=(start+end)>>1;
        mergeSort(nums,start,mid,ans);
        mergeSort(nums,mid+1,end,ans);
        merge(nums,start,end,ans,mid);
        
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
        mergeSort(nums,0,nums.size()-1,ans);
        return ans;
    }
};