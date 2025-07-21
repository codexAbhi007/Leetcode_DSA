// https://leetcode.com/problems/sum-of-subarray-ranges/description/

class Solution {
public:
    // Next Smaller Element
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    // Previous Smaller or Equal Element
    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    // Next Greater Element
    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    // Previous Greater or Equal Element
    vector<int> findPGEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pgee(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);
        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);

        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; ++i) {
            long long leftMin = i - psee[i];
            long long rightMin = nse[i] - i;
            minSum += nums[i] * leftMin * rightMin;

            long long leftMax = i - pgee[i];
            long long rightMax = nge[i] - i;
            maxSum += nums[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
    }
};
