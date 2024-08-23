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
        int res1 = helper(nums, n, true);
        int res2 = helper(nums, n, false);
        return max(res1, res2);
    }

private:
    int helper(vector<int> nums, int n, bool includeLast) {
        if (!includeLast)
            nums[n-1] = 0;
        for (int i = n - 3; i >= 0; --i) {
            if (i == n - 3) {
                nums[i] += nums[i+2];
            } else {
                nums[i] += max(nums[i+2], nums[i+3]);
            }
        }
        if (includeLast)
            return max(nums[1], nums[2]);
        else
            return nums[0];
    }
};