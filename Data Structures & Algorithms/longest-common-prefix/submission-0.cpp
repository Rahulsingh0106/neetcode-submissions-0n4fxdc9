class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for(string str : strs){
            while(!str.starts_with(prefix)){
                int n = prefix.length();
                prefix = prefix.substr(0, n - 1);
            }
        }
        return prefix;
    }
};