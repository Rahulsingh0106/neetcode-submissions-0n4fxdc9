class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(dfs(row, col, 0, board, word, visited)){
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(int row, int col, int index, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited){
        int rows = board.size();
        int cols = board[0].size();

        if(index == word.size()){
            return true;
        }

        if(row < 0 || row >= rows || col < 0 || col >= cols){
            return false;
        }

        if(visited[row][col]){
            return false;
        }
        if(board[row][col] != word[index]){
            return false;
        }

        visited[row][col] = true;

        bool found = dfs(row - 1, col, index + 1, board, word, visited) ||
        dfs(row + 1, col, index + 1, board, word, visited) ||
        dfs(row, col - 1, index + 1, board, word, visited) ||
        dfs(row, col + 1, index + 1, board, word, visited);

        visited[row][col] = false;
        return found;
    }
};
