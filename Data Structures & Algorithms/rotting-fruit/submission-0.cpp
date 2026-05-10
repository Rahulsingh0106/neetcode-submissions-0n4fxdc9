class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        // Step 1:
        // Find all rotten oranges
        // Count fresh oranges
        for(int row = 0; row < rows; row++) {

            for(int col = 0; col < cols; col++) {

                if(grid[row][col] == 2) {
                    q.push({row, col});
                }

                else if(grid[row][col] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        // directions
        vector<pair<int,int>> directions = {
            {-1,0}, // up
            {1,0},  // down
            {0,-1}, // left
            {0,1}   // right
        };

        // BFS
        while(!q.empty() && fresh > 0) {

            int size = q.size();

            // process one BFS level
            for(int i = 0; i < size; i++) {

                auto current = q.front();
                q.pop();

                int row = current.first;
                int col = current.second;

                // explore neighbors
                for(auto dir : directions) {

                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    // boundary check
                    if(newRow >= 0 && newRow < rows &&
                       newCol >= 0 && newCol < cols &&

                       // fresh orange check
                       grid[newRow][newCol] == 1) {

                        // make rotten
                        grid[newRow][newCol] = 2;

                        // reduce fresh count
                        fresh--;

                        // push into queue
                        q.push({newRow, newCol});
                    }
                }
            }

            // one level completed
            minutes++;
        }

        // still fresh oranges left
        if(fresh > 0) {
            return -1;
        }

        return minutes;
    }
};
