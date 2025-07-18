// https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!st.empty() && st.top() <= nums2[idx]) {
                st.pop();
            }
            if (i < n) {
                if (!st.empty()) ans[idx] = st.top();
            }
            st.push(nums2[idx]);
        }

        return ans;
    }
};