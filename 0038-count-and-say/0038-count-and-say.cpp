
class Solution {
public:
    string countAndSay(int n) {

        string ans = "1";

        for(int i = 1; i < n; i++) {

            string temp = "";

            int j = 0;

            while(j < ans.size()) {

                int count = 0;
                char ch = ans[j];

                // Count consecutive identical characters
                while(j < ans.size() && ans[j] == ch) {
                    count++;
                    j++;
                }

                // Append count followed by character
                temp += to_string(count);
                temp += ch;
            }

            ans = temp;
        }

        return ans;
    }
};
