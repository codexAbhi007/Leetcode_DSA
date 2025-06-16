// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int i = 1;
        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[j] != nums[i - 1])
            {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};

int main()
{
    vector<int> nums = {0, 0, 1, 1, 2, 2, 3, 3, 4};

    Solution sol;
    int k = sol.removeDuplicates(nums);

    // Output the result
    cout << "k = " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
