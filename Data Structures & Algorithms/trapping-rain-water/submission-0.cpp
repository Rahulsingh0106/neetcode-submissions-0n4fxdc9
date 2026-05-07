class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        for(int i = 0; i < n; i++){
            int maxLeft = 0;
            int maxRight = 0;

            for(int j = 0; j <= i; j++){
                maxLeft = max(maxLeft, height[j]);
            }

            for(int j = i; j < n; j++){
                maxRight = max(maxRight, height[j]);
            }

            int water = min(maxLeft, maxRight) - height[i];

            totalWater += water;
        }
        return totalWater;
    }
};
