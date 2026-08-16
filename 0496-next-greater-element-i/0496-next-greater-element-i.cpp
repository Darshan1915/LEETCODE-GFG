class Solution {
public:

    int findNextGreter(vector<int>& nums1, vector<int>& nums2, int start, int value){
        for(int j = start; j<nums2.size(); j++ ){
            if(nums2[j] > value){
                return nums2[j];
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());

        for(int i=0; i<nums1.size();i++){
            for(int j=0; j<nums2.size();j++){
                if (nums1[i] == nums2[j]){
                      
                    int x = findNextGreter(nums1, nums2, j, nums1[i]);
                    ans[i] = x;

                }
                    

            }
        }

        return ans;
    }
};