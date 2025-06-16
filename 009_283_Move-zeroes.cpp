//https://leetcode.com/problems/move-zeroes/

#include <iostream>
#include <vector>
#include <algorithm> // for std::swap
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                swap(nums[j], nums[i]);
                ++i;
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    Solution sol;
    sol.moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
