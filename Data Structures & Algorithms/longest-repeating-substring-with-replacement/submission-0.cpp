class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);  // for A-Z

        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for(int right = 0; right < s.size(); right++){
            
            freq[s[right] - 'A']++;

            // track most frequent char in current window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // check if window is invalid
            while((right - left + 1) - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};