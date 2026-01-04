// https://leetcode.com/problems/rotting-oranges/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Push all rotten oranges & count fresh ones
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        // Edge cases
        if(fresh == 0) return 0;     // no fresh oranges
        if(q.empty()) return -1;     // no rotten to start rotting

        int time = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        
        while(!q.empty()) {
            int sz = q.size();
            bool rotted = false;

            for(int i = 0; i < sz; i++) {
                pair<int,int> p = q.front();
                int r = p.first;
                int c = p.second;
                q.pop();

                for(int d = 0; d < 4; d++) {
                    int nr = r + delrow[d];
                    int nc = c + delcol[d];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2; 
                        fresh--;
                        q.push({nr, nc});
                        rotted = true;
                    }
                }
            }

            if(rotted) time++;
        }

        return (fresh == 0) ? time : -1;
    }
};
