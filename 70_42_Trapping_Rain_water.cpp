// https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lMax = 0, rMax = 0;         // initialize lMax and rMax to 0
        int total = 0;                  // also initialize total to 0

        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < lMax) {
                    total += lMax - height[l];
                } else {
                    lMax = height[l];
                }
                l++;
            } else {
                if (height[r] < rMax) {
                    total += rMax - height[r];
                } else {
                    rMax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};
