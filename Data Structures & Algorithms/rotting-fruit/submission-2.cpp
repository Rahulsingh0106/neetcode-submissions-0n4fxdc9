class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int minutes = 0;
        int fresh = 0;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 1){
                    fresh++;
                }

                else if(grid[row][col] == 2){
                    q.push({row, col});
                }
            }
        }

        vector<pair<int, int>> directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while(!q.empty() && fresh > 0){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto current = q.front();
                q.pop();
                int row = current.first;
                int col = current.second;

                for(auto dir : directions){
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if(newRow < rows && newRow >= 0 && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1){
                        fresh--;
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                    }
                }
            }
            minutes++;
        } 
        if(fresh > 0){
            return -1;
        }
        return minutes;  
    }
};
