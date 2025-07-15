// https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y; // XOR gives bits that differ
        int cnt = 0;
        while (ans != 0) {
            cnt += ans & 1; // count the number of 1s
            ans >>= 1;
        }
        return cnt;
    }
};