#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = nums[0], maxVal = nums[0];
        
        // Find min and max
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        
        // Store elements in set
        unordered_set<int> s(nums.begin(), nums.end());
        
        vector<int> result;
        
        // Check missing numbers
        for (int i = minVal; i <= maxVal; i++) {
            if (!s.count(i)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};