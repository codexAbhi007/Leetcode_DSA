// https://leetcode.com/problems/flood-fill/description/

class Solution {

private:
    void dfs(vector<vector<int>> &image, vector<vector<int>> &res, int row, int col, int newColor,
    int initialColor){
        res[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        for(int i = 0; i < 4; ++i){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && 
                res[nrow][ncol] != newColor){
                    dfs(image,res,nrow,ncol,newColor,initialColor);
                }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
        int initialColor = image[sr][sc];
        if(initialColor == color) return image;

         vector<vector<int>> res = image;
        dfs(image, res, sr,sc,color,initialColor);

        return res;
    }
};