class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int cntK = 0;
        for (int num : nums)
            if (num == k)
                cntK++;

        int ans = cntK;

        for (int v = 1; v <= 50; v++) {
            if (v == k)
                continue;

            int curr = 0, best = 0;

            for (int num : nums) {
                int score = 0;

                if (num == v)
                    score = 1;
                else if (num == k)
                    score = -1;

                curr = max(0, curr + score);
                best = max(best, curr);
            }

            ans = max(ans, cntK + best);
        }

        return ans;
    }
};