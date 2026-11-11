class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i<board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (bt(board, word, used, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
private: 
    bool bt(vector<vector<char>>& board, const string &word, vector<vector<bool>> &used, int index, int i, int j){
        if (index == word.length()){
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j>= board[0].size() || used[i][j] == true || board[i][j] != word[index]){
            return false;
        }
        
        used[i][j] = true;
        bool found = bt(board, word, used, index + 1, i + 1, j) ||
        bt(board, word, used, index + 1, i - 1, j) ||
        bt(board, word, used, index + 1, i, j+1) ||
        bt(board, word, used, index + 1, i, j-1);
        used[i][j] = false;

        return found;
    }
};
