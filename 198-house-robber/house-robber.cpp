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