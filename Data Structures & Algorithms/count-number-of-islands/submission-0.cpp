class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    count ++;
                    bfs(i, j, grid);
                }
            }
        }
        return count;
    }
private:
    void bfs(int sr, int sc, vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        grid[sr][sc] = '0';

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [r, c] = q.front(); 
            q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (grid[nr][nc] != '1') continue;
                grid[nr][nc] = '0'; 
                q.push({nr, nc});
            }
        }
    }
};
