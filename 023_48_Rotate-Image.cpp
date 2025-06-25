// https://leetcode.com/problems/rotate-image/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i;
        int j;
        int n = matrix.size();

        for(i = 0 ; i < n - 1; ++i){
            for(j = i + 1; j < n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(i = 0; i < n; ++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};