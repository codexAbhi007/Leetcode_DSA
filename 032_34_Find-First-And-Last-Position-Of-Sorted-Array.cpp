// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int> &arr, int n, int target){
        int low = 0;
        int high = n - 1;
        int ans = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // maybe an answer
            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> &arr, int n, int target){
        int low = 0;
        int high = n - 1;
        int ans = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // maybe an answer
            if(arr[mid] > target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums,n, target);
        if(lb == n || nums[lb] != target) return {-1,-1};
        return {lb, upperBound(nums,n,target) - 1};
    }
};