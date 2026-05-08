class Solution {

public:
void dfs(int row, int col, vector<vector<char>>& graph, vector<vector<bool>>& visited){
	int rows = graph.size();
    int cols = graph[0].size();
    
    if(row < 0 || row >= rows || col < 0 || col >= cols){
    	return;
    }
    
    if(graph[row][col] == '0'){
    	return;
    }
    
    if(visited[row][col]){
    	return;
    }
    
    visited[row][col] = true;
    dfs(row - 1, col, graph, visited);
    dfs(row + 1, col, graph, visited);
    dfs(row, col - 1, graph, visited);
    dfs(row, col + 1, graph, visited);
}
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int count = 0;
    
    for(int row = 0; row < rows; row++){
    	for(int col = 0; col < cols; col++){
        	if(grid[row][col] == '1' && !visited[row][col]){
            	count++;
            	dfs(row, col, grid, visited);
            }
        }
    }
    return count;

        
    }
};
