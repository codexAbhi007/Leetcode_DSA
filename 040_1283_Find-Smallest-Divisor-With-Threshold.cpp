// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(vector<int> &arr){
        int maxi = INT_MIN;
        for(int i = 0; i < arr.size(); ++i){
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
    bool isSumThreshold(vector<int>& nums, int divisor,int threshold){
        int sum = 0;
        int n = nums.size();
        int i;
        for(i = 0; i < n; ++i){
            sum += ceil((double)nums[i]/divisor);
        }
        if(sum <= threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = findMax(nums);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isSumThreshold(nums,mid,threshold)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};