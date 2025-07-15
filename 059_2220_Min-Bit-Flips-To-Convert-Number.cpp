// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int ans = start ^ goal; // XOR gives bits that differ
        int cnt = 0;
        while (ans != 0)
        {
            cnt += ans & 1; // count the number of 1s
            ans >>= 1;
        }
        return cnt;
    }
};
