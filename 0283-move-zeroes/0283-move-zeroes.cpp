class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};






//wronggggg:-


// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         int left = 0, right = n-1;
//         while(left<=right){
//             if(nums[left]==0){
//                 swap(nums[left],nums[right]);
//                 right--;
//             }
//             left++;
//         }
//     }
// };