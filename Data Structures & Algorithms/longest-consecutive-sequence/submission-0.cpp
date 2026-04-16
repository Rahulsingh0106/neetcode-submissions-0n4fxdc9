class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values;
        int maxLength = 0;

        for(int i = 0; i < nums.size(); i++){
            values.insert(nums[i]);
        }


    for(int num : nums){

        if (values.find(num - 1) == values.end()){

            int current = num;
            int length = 1;

            while(values.find(current + 1) != values.end()){
                current = current + 1;
                length = length + 1;
            }
            maxLength = max(maxLength, length);
        }
    }
    return maxLength;
    }
};
