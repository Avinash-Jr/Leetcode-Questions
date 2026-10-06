class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        // Opening brackets → push expected closing
        if (ch == '(') st.push(')');
        else if (ch == '{') st.push('}');
        else if (ch == '[') st.push(']');
        // Closing brackets → validate
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty() || st.top() != ch)
                return false;
            st.pop();
        }
        // Ignore other characters (a, +, *, etc.)
    }
    return st.empty();
    }
};