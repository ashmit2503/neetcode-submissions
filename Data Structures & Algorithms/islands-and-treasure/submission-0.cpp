class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j]) q.push({i,j});
            }
        }
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != INT_MAX) continue;
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }
};
