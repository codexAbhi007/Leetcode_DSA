// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        stack<int> st;
        for(char c : s)
            if(c=='(')
            {
                st.push(c);
                int sz = st.size();
                mx = max(mx,sz);
            }
            else if(c==')')
                st.pop();
        return mx;
    }
};