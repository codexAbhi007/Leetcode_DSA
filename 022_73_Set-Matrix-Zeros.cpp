#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Step 1: Create marker arrays for rows and columns
        vector<int> rowMark(rows, 0);
        vector<int> colMark(cols, 0);

        // Step 2: Mark the rows and columns that need to be zeroed
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    rowMark[i] = 1;
                    colMark[j] = 1;
                }
            }
        }

        // Step 3: Update the matrix using the markers
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (rowMark[i] || colMark[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
