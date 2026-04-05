class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int diff = 0;
        unordered_map<int, int> num;
        for(int i = 0; i < nums.size(); i++){
            diff = target - nums[i];
            if(num.find(diff) != num.end()){
                return {num[diff], i};
            }
            num[nums[i]] = i;
        }
        return {};
    }
};
