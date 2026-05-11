class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            // Opening brackets
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }

            // Closing brackets
            else {

                // stack empty means invalid
                if(st.empty()) {
                    return false;
                }

                // check matching
                if( (s[i] == ')' && st.top() == '(') ||
                    (s[i] == ']' && st.top() == '[') ||
                    (s[i] == '}' && st.top() == '{') ) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // stack should be empty finally
        return st.empty();
    }
};