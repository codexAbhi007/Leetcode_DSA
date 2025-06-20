//https://leetcode.com/problems/sort-colors/description/

//* Approach 1 -> Better  o(n^2) o(1)
//* Approach 2 -> Optimal - Dutch National Flag Algorithm o(n) o(1)
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_zero = 0;
        int count_one = 0;
        int count_two = 0;

        int i;
        for(i = 0; i < nums.size(); ++i){
            if(nums[i] == 0) count_zero++;
            else if(nums[i] == 1) count_one++;
            else count_two++;
        }

        for(i = 0; i < count_zero; ++i) nums[i] = 0;
        for(i = count_zero; i < count_zero + count_one;++i) nums[i] = 1;
        for(i = count_zero + count_one; i < nums.size(); ++i) nums[i] = 2;
    }
};

//*Dutch National Flag Algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                ++low;
                ++mid;
            } else if (nums[mid] == 1) {
                ++mid;
            } else {
                swap(nums[mid], nums[high]);
                --high; 
            }
        }
    }
};