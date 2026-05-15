class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // n = nums.size()
        // 2^n combinations to test
        vector<int> result;
        vector<vector<int>> results;
        ranges::sort(nums);
        backtrack(nums, target, result, results);
        return results;
    }

private:
    void backtrack(const span<const int> nums, int target, vector<int>& result, vector<vector<int>>& results) {
        if (target == 0) {
            results.emplace_back(result);
            return;
        }
        if (nums.empty() || target < nums[0]) {
            return;
        }

        result.push_back(nums[0]);
        backtrack(nums, target - nums[0], result, results);
        result.pop_back();

        backtrack(nums.subspan(1), target, result, results);
    }
};
