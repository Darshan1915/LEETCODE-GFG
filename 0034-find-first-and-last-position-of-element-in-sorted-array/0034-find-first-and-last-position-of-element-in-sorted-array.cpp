class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {


        vector<int> result(2, -1);  // Initialize result to [-1, -1] with sze 2
        
        // Find the first occurrence
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result[0] = mid;   // Record the index
                high = mid - 1;    // Keep searching to the left
            } else if (nums[mid] < target) {
                low = mid + 1;     // Search the right half
            } else {
                high = mid - 1;    // Search the left half
            }
        }
        
        // Find the last occurrence
        low = 0, high = nums.size() - 1; // Reset the pointers
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result[1] = mid;   // Record the index
                low = mid + 1;     // Keep searching to the right
            } else if (nums[mid] < target) {
                low = mid + 1;     // Search the right half
            } else {
                high = mid - 1;    // Search the left half
            }
        }
        
        return result;






         
            // int n = nums.size();
            // int low = 0, high =(n-1), ans = -1;

            // while(low<=high){
            //     int mid = (low+high)/2;
            //     if(nums[mid]>=target){
            //         ans = mid;
            //         high = mid-1;
            //     }
            //     else{
            //         low =  mid+1;
            //     }
            // }
            // return ans;
        


       
            // int low = 0, high = nums.size() - 1, ans = -1;
            // while (low <= high) {
            //     int mid = low + (high - low) / 2;
            //     if (nums[mid] == target) {
            //         ans = mid; // Record the index
            //         low = mid + 1; // Look for later occurrences
            //     } else if (nums[mid] < target) {
            //         low = mid + 1; // Search the right half
            //     } else {
            //         high = mid - 1; // Search the left half
            //     }
            // }
            // return ans;
        


        // int n = nums.size();
        // int low = 0, high =(n-1), ans = -1;

        // while(low<=high){
        //     int mid = (low+high)/2;
        //     if(nums[mid]>=target){
        //         ans = mid;
        //         high = mid-1;
        //     }
        //     else{
        //         low =  mid+1;
        //     }
        // }
        // return ans;
   
    }
};