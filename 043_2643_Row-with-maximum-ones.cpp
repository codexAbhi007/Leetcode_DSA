// https://leetcode.com/problems/row-with-maximum-ones/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();           // number of rows
        int m = mat[0].size();        // number of columns
        int index = 0;               // index of row with max 1s
        int cnt_max = 0;              // maximum number of 1s in a row

        for (int i = 0; i < n; ++i) {
            int cnt_ones = 0;
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1)
                    cnt_ones++;
            }
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }

        return {index, cnt_max};
    }
};
