class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, 0);    // Frequency array for ASCII characters
        int left = 0;     // Left boundary of sliding window
        int maxLen = 0;  
        for (int right = 0; right < s.size(); right++) {    // Right boundary of sliding window
        // Expands the window one character at a time
            freq[s[right]]++;
             /*
                If frequency becomes greater than 1,
                current character is duplicated.

                Shrink the window from the left side
                until the duplicate is removed.
            */
            while (freq[s[right]] > 1) {
                freq[s[left]]--;      // Remove leftmost character from window
                left++;     // Move left boundary forward
            }
            /*
                At this point the window contains
                only unique characters.

                Current window length:
                right - left + 1
            */
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
