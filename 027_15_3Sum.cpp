// https://leetcode.com/problems/3sum/

// #include <iostream>
// #include <vector>
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int i;
    //     int j;
    //     int k;
    //     int n = nums.size();
    //     vector<vector<int>> result;
    //     for(i = 0; i<n; ++i){
    //         for(j = i + 1; j < n; ++j){
    //             for(k = j + 1; k < n; ++k){
    //                 vector<int> temp;
    //                 if (nums[i] + nums[j] + nums[k] == 0 && (i != j && i !=k && j != k)){
    //                     temp = {nums[i],nums[j],nums[k]};
    //                     sort(temp.begin(), temp.end());
    //                     auto it = find(result.begin(), result.end(),temp);
    //                     if(it == result.end()){
    //                         result.push_back(temp);

    //                     }

    //                 }
    //             }
    //         }
    //     }

    //     return result;
    // }
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     set<vector<int>> st;
    //     int n = nums.size();
    //     int i;
    //     for(i = 0; i < n; ++i){
    //         set<int> hashset;
    //         for(int j = i +1; j<n; ++j){
    //             int k = -(nums[i] + nums[j]);
    //             if(hashset.find(k) != hashset.end()){
    //                 vector<int> temp = {nums[i],nums[j], k};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp);
                    
    //             }
    //             hashset.insert(nums[j]);
    //         }
    //     }
    //     vector<vector<int>> ans(st.begin(), st.end());
    //     return ans;

    // }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i;
        for(i = 0; i < n; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n -1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) ++j;
                else if(sum > 0) --k;
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    ++j; --k;
                    while(j < k && nums[j] == nums[j-1]) ++j;
                    while(j < k && nums[k] == nums[k+1]) --k;
                }
            }
        }
        return ans;
    }
};