class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            // Match found
            if (s[i] == t[j])
                i++;
            // Always move through t
            j++;
        }
        return i == s.size();
    }
};