class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& image, int originalColor, int newColor){
        int rows = image.size();
        int cols = image[0].size();

        if(sr < 0 || sr >= rows || sc < 0 || sc >= cols){
            return;
        }

        if(image[sr][sc] != originalColor){
            return;
        }
        
        if(image[sr][sc] == newColor){
            return;
        }

        image[sr][sc] = newColor;
        dfs(sr - 1, sc, image, originalColor, newColor);
        dfs(sr + 1, sc, image, originalColor, newColor);
        dfs(sr, sc - 1, image, originalColor, newColor);
        dfs(sr, sc + 1, image, originalColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int originalColor = image[sr][sc];
        if(originalColor == color){
            return image;
        }

        dfs(sr, sc, image, originalColor, color);
        return image;
    }
};