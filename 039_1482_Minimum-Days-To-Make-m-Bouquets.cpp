// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool isPossible(vector<int> &arr, int day, int m, int k){
        int count = 0;
        int bouquets_count = 0;
        int i;
        for(i = 0; i < arr.size(); ++i){
            if(arr[i] <= day){ //bloomed
                count++;
            }
            else {
                bouquets_count += (count / k);
                count = 0;
            }
        }
        bouquets_count += (count / k);
        if(bouquets_count >= m) return true;
        return false;
    }

    int findMax(vector<int> &arr){
        int maxi = INT_MIN;
        for(int i = 0; i < arr.size(); ++i){
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
    int findMin(vector<int> &arr){
        int mini = INT_MAX;
        for(int i = 0; i < arr.size(); ++i){
            mini = min(mini, arr[i]);
        }
        return mini;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) return -1;
        int low = findMin(bloomDay);
        int high = findMax(bloomDay);
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(bloomDay,mid,m,k) == true){
                ans = mid;
                high = mid -1 ;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};