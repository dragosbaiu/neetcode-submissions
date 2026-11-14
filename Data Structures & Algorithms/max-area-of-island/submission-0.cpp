class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[0].size(); j++){
                if (grid[i][j] == 1){
                    max = std::max(max, bfs(i, j, grid));
                }
            }
        }
        return max;
    }
private:
    int bfs (int sr, int sc, vector<vector<int>>& grid){
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        count++;
        grid[sr][sc] = 0;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (grid[nr][nc] != 1) continue;
                grid[nr][nc] = 0;
                count++;
                q.push({nr, nc});
            }
        }
        return count;
    }
};
