class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int minHeight = INT_MAX;
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int dist = 0;
                minHeight = min(heights[i], heights[j]);
                maxArea = max(maxArea, minHeight * (j - i));
            }
        }
        return maxArea;
    }
};