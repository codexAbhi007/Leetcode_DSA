// https://leetcode.com/problems/find-the-highest-altitude/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int maxAltitude = 0;
        int currentAltitude = 0;

        for (int i = 0; i < gain.size(); i++)
        {
            currentAltitude += gain[i];
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};