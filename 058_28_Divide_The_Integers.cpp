// https://leetcode.com/problems/divide-two-integers/?submissionId=1697189653
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // Write your code here.
        if (dividend == divisor)
            return 1;
        bool sign = true;
        if (dividend >= 0 && divisor < 0)
            sign = false;
        else if (dividend <= 0 && divisor > 0)
            sign = false;
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long q = 0;
        while (n >= d)
        {
            int cnt = 0;
            while (n >= (d << (cnt + 1)))
            {
                cnt += 1;
            }
            q += 1 << cnt;
            n -= (d << cnt);
        }
        if (q == (1 << 31) && sign)
            return INT_MAX;
        if (q == (1 << 31) && !sign)
            return INT_MIN;

        return sign ? q : -q;
    }
};