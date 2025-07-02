// https://leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>
using namespace std;
//* 1) Brute Force

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        int i;
        for (i = 0; i < n; ++i)
        {
            if (cnt1 == 0 && el2 != nums[i])
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i])
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1)
                cnt1++;
            else if (nums[i] == el2)
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> result;
        cnt1 = 0;
        cnt2 = 0;
        for (i = 0; i < n; ++i)
        {
            if (el1 == nums[i])
                cnt1++;
            if (el2 == nums[i])
                cnt2++;
        }
        int minimum_threshold = int(n / 3) + 1;
        if (cnt1 >= minimum_threshold)
            result.push_back(el1);
        if (cnt2 >= minimum_threshold)
            result.push_back(el2);

        return result;
    }
};