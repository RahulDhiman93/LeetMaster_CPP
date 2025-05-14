class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> nums1(nums.begin()+1, nums.end());
        vector<int> nums2(nums.begin(), nums.end()-1);
 
        return max(nums[0], max(helper(nums1), helper(nums2)));
    }

private:
    int helper(vector<int> nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }

        for(int i = n - 3; i >= 0; i--) {
            if (i == n - 3) {
                nums[i] += nums[i+2];
            } else {
                nums[i] += max(nums[i+2], nums[i+3]);
            }
        }

        return max(nums[0], nums[1]);
    }
};