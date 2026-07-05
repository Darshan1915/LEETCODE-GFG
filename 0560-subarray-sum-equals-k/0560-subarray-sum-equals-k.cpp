// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {

//         int n = nums.size();

//         vector<int> prefixSum(n);

//         int sum = 0;
//         for(int i = 0; i < n; i++) {
//             sum += nums[i];
//             prefixSum[i] = sum;
//         }

//         int count = 0;

//         for(int i = 0; i < n; i++) {
//             for(int j = i; j < n; j++) {

//                 int subarraySum;

//                 if(i == 0)
//                     subarraySum = prefixSum[j];
//                 else
//                     subarraySum = prefixSum[j] - prefixSum[i - 1];

//                 if(subarraySum == k)
//                     count++;
//             }
//         }

//         return count;
//     }
// };


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Prefix sum 0 has occurred once
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Current prefix sum
            sum += nums[i];

            // If (sum - k) existed before,
            // then there is a subarray with sum = k.
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};