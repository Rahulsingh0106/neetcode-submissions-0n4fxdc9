class Solution {
public:
    void dfs(int row, vector<vector<int>>& isConnected, vector<bool>& visited){
        int cols = isConnected[row].size();
        visited[row] = true;

        for(int col = 0; col < cols; col++){
            if(isConnected[row][col] == 1 && !visited[col]){
                dfs(col, isConnected, visited);
           }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<bool> visited(cities, false);
        int provinceCount = 0;

        for(int city = 0; city < cities; city++){
            if(!visited[city]){
                provinceCount++;
                dfs(city, isConnected, visited);
            }
        }
        return provinceCount;
    }

};