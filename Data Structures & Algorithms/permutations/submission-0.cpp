class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> current;
        vector<vector<int>> result;
        vector<bool> used(n, false);
        solve(used, current, nums, result);

        return result;
    }

private:
    void solve(vector<bool>& used, vector<int>& current, vector<int>& nums, vector<vector<int>>& result){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]){
                continue;
            }

            used[i] = true;

            current.push_back(nums[i]);

            solve(used, current, nums, result);

            current.pop_back();
            used[i] = false;
        }
    }
};
