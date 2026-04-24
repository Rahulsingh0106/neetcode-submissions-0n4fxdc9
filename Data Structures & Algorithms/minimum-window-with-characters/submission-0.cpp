class Solution {
public:
    string minWindow(string s, string t) {

        if(s.empty() || t.empty()) return "";

        unordered_map<char, int> freqT;
        unordered_map<char, int> window;

        // count characters in t
        for(char c : t){
            freqT[c]++;
        }

        int required = freqT.size();  // unique chars in t
        int formed = 0;

        int left = 0, right = 0;

        int minLen = INT_MAX;
        int start = 0;

        while(right < s.size()){

            char c = s[right];
            window[c]++;

            // check if current char satisfies required frequency
            if(freqT.count(c) && window[c] == freqT[c]){
                formed++;
            }

            // try to shrink window
            while(left <= right && formed == required){

                // update answer
                if((right - left + 1) < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                char ch = s[left];
                window[ch]--;

                if(freqT.count(ch) && window[ch] < freqT[ch]){
                    formed--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};