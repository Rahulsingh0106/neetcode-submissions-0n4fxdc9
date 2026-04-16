class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> unmap;
        int composite = 0;

        for(int i = 0; i <= nums.size(); i++){
            composite = target - nums[i];
            if(unmap.find(composite) != unmap.end()){
                return {unmap[composite], i};
            }
            unmap[nums[i]] = i; 
        }
        return {};
    }
};
