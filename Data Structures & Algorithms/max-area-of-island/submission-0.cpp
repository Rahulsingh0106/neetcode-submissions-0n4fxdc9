class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int rows = grid.size();
        int cols = grid[0].size();

        int area = 1;
        if(row < 0 || row >= rows || col < 0 || col >= cols){
            return 0;
        }

        if(visited[row][col]){
            return 0;
        }

        if(grid[row][col] == 0){
            return 0;
        }

        visited[row][col] = true;
        area += dfs(row - 1, col, grid, visited);
        area += dfs(row + 1, col, grid, visited);
        area += dfs(row, col - 1, grid, visited);
        area += dfs(row, col + 1, grid, visited);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 1 && !visited[row][col]){
                    int area = dfs(row, col, grid, visited);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
