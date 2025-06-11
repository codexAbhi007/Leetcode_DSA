#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (seen.find(complement) != seen.end())
            {
                return {seen[complement], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = solution.twoSum(nums, target);

    cout << "Indices of the two numbers that add up to " << target << " are: ";
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
