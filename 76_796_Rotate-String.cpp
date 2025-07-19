// https://leetcode.com/problems/rotate-string/description/

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size()==goal.size() && (s+s).find(goal) < s.size();
    }
};