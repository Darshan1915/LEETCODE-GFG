class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // nums1.sort(nums1.begin(),nums1.end());
        // nums2.sort(nums2.begin(),nums2.end());

        // int n = nums1.size();

        // int i = 0;

        // vector<int> ans;

        // int leftArry, rightArry = 0;

        // while(i<n){
        //     if(nums1[leftArry] == nums2[rightArry]) ans.push_back(nums1[leftArry]);
        //     while(nums2[rightArry] == nums2[rightArry])
        // }



// 💡 Steps:
// Convert nums1 into a set
// Traverse nums2
// If element exists in set → add to result set
// Convert result set to vector/array




        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int num : nums2) {
            if (set1.count(num)) {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }

    


};