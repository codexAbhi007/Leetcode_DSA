#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = 1; // base case: sum 0 occurs once

        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (prefixSumMap.find(sum - k) != prefixSumMap.end()) {
                count += prefixSumMap[sum - k];
            }

            prefixSumMap[sum]++;
        }

        return count;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 3;

    int result = sol.subarraySum(nums, k);
    cout << "Total number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}
