class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int minHeight = INT_MAX;
        int maxArea = 0;
        int left = 0;
        int right = n - 1;
        int area = 0;
        while(left < right){
            minHeight = min(heights[left], heights[right]);
            area = minHeight * (right - left);
            maxArea = max(area, maxArea);
            if(heights[left] < heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};