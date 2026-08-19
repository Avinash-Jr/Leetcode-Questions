class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        // Step 1: Remove extra spaces
        int i = 0;
        int j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ')
                j++;
            while (j < n && s[j] != ' ')
                s[i++] = s[j++];
            while (j < n && s[j] == ' ')
                j++;
            if (j < n)
                s[i++] = ' ';
        }

        s.resize(i);
        // Step 2: Reverse the entire string
        reverse(s.begin(), s.end());
        // Step 3: Reverse every individual word
        int start = 0;
        for (int end = 0; end <= s.length(); end++) {
            if (end == s.length() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
    }
};