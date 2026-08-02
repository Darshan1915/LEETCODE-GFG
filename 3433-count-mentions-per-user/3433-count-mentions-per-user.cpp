class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

        sort(events.begin(), events.end(), [](auto &a, auto &b) {

            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);

            if (t1 == t2) {
                if (a[0] == b[0]) return false;
                return a[0] == "OFFLINE";
            }

            return t1 < t2;
        });

        vector<int> ans(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);
        vector<int> backTime(numberOfUsers, -1);

        for (auto &e : events) {

            int time = stoi(e[1]);

            // Bring users back online
            for (int i = 0; i < numberOfUsers; i++) {
                if (!online[i] && backTime[i] <= time) {
                    online[i] = true;
                }
            }

            if (e[0] == "OFFLINE") {

                int id = stoi(e[2]);
                online[id] = false;
                backTime[id] = time + 60;
            }
            else {

                string s = e[2];

                if (s == "ALL") {

                    for (int i = 0; i < numberOfUsers; i++)
                        ans[i]++;
                }
                else if (s == "HERE") {

                    for (int i = 0; i < numberOfUsers; i++)
                        if (online[i])
                            ans[i]++;
                }
                else {

                    stringstream ss(s);
                    string token;

                    while (ss >> token) {
                        int id = stoi(token.substr(2));
                        ans[id]++;
                    }
                }
            }
        }

        return ans;
    }
};