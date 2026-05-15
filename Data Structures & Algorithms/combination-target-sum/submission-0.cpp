class Solution {
public:
    void solve(int index,  int target, vector<int>& nums, vector<int>& current, 
    vector<vector<int>>& result){
        if(target == 0){
            result.push_back(current);
            return;
        }

        if(target < 0 || index >= nums.size()){
            return;
        }

        current.push_back(nums[index]);
        solve(index, target - nums[index], nums, current, result);

        current.pop_back();
        solve(index + 1, target, nums, current, result);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        vector<vector<int>> result;
        solve(0, target, nums, current, result);

        return result;
    }
};
