class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        } else if (n == 3) {
            return max(nums[0], max(nums[1], nums[2]));
        }

        vector<int> nums2 = nums;
        nums2[n-1] = 0;
        for (int i = n - 3; i >= 0; --i) {
            if (i == n - 3) {
                nums[i] += nums[i+2];
            } else {
                nums[i] += max(nums[i+2], nums[i+3]);
                nums2[i] += max(nums2[i+2], nums2[i+3]);
            }
        }
        return max(nums2[0], max(nums[1], nums[2]));
    }
};