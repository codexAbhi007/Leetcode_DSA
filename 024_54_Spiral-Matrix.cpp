// https://leetcode.com/problems/spiral-matrix/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        int cols =matrix[0].size();
        int top =0;
        int right = cols-1;
        int bottom = rows-1;
        int left = 0;
        int i,j;
        while(top <= bottom && left <= right){
            for(i=left;i <=right; ++i){
                result.push_back(matrix[top][i]);
            }
            ++top;
            for(i=top;i<=bottom;++i){
                result.push_back(matrix[i][right]);
            }
            --right;
            if(top<=bottom){
                for(i=right; i>=left;--i){
                    result.push_back(matrix[bottom][i]);
                }
                --bottom;
            }
            if(left <= right){
                for(i=bottom; i >=top; --i){
                    result.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return result;
    }
};