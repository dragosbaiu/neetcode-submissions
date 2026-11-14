class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(columns, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(columns, false));
        queue<pair<int, int>> qp;
        queue<pair<int, int>> qa;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j< columns; j++){
                if (i == 0 || j == 0){
                    pacific[i][j] = true;
                    qp.push({i, j});
                }
                if (i == rows-1 || j == columns-1){
                    atlantic[i][j] = true;
                    qa.push({i, j});
                }
            }
        }

        int dr[4] = {-1, 0, 0, 1};
        int dc[4] = {0, -1, 1, 0};

        while(!qp.empty()){
            auto [r, c] = qp.front();
            qp.pop();
            for (int k = 0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= columns) continue;
                if (heights[nr][nc] < heights[r][c]) continue;
                if (pacific[nr][nc] == true) continue;
                pacific[nr][nc] = true;
                qp.push({nr, nc});
            }
        }

        while(!qa.empty()){
            auto [r, c] = qa.front();
            qa.pop();
            for (int k = 0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= columns) continue;
                if (heights[nr][nc] < heights[r][c]) continue;
                if (atlantic[nr][nc] == true) continue;
                atlantic[nr][nc] = true;
                qa.push({nr, nc});
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j< columns; j++){
                if (pacific[i][j] == true && atlantic[i][j] == true){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
