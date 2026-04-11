class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int left = 0;
    int maxLength = 0;
    unordered_set<char> result;

        for(int right = 0; right < s.size(); right++){
            while(result.contains(s[right])){
                result.erase(s[left]);
                left++;
            }
            result.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        } 
        return maxLength;       
    }
};
