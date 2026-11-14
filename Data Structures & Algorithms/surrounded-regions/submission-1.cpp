class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> surrounded(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++){
            for (int j = 0; j< cols; j++){
                if (board[i][j] == 'O' && (i == 0 || j == 0 || i == rows-1 || j == cols - 1 )){
                    surrounded[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        int dr[4] = {-1, 0, 0, 1};
        int dc[4] = {0, -1, 1, 0};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k< 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (board[nr][nc] != 'O') continue;
                if (surrounded[nr][nc]) continue;
                surrounded[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (surrounded[i][j]){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};
