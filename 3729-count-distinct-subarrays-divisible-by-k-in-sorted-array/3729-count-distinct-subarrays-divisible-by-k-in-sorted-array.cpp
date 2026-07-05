class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int prefix = 0;

        unordered_map<int, int> cnt;
        cnt[0] = 1;

        // Count all good subarrays using prefix sum modulo k
        for (int x : nums) {
            prefix = (prefix + x) % k;
            ans += cnt[prefix];
            cnt[prefix]++;
        }

        // Remove duplicate subarrays consisting of identical values
        int n = nums.size();

        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i])
                j++;

            int len = j - i;

            for (int h = 1; h <= len; h++) {
                if ((1LL * nums[i] * h) % k == 0) {
                    ans -= (len - h);
                }
            }

            i = j;
        }

        return ans;
    }
};



// class Solution {
// public:
//     long long numGoodSubarrays(vector<int>& nums, int k) {

//         set<vector<int>> st;
//         int n = nums.size();

//         for(int i = 0; i < n; i++) {

//             vector<int> temp;
//             long long sum = 0;

//             for(int j = i; j < n; j++) {

//                 temp.push_back(nums[j]);
//                 sum += nums[j];

//                 if(sum % k == 0)
//                     st.insert(temp);
//             }
//         }

//         return st.size();
//     }
// };