class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        for(int num: nums)
            res = max(res, num);
            
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int curMax = 1, curMin = 1;
        for(int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                curMax = 1; curMin = 1;
                continue;
            }
            int temp = nums[i] * curMax;
            curMax = max(nums[i], max(nums[i] * curMax, nums[i] * curMin));
            curMin = min(nums[i], min(temp, nums[i] * curMin));
            res = max(res, max(curMax, curMin));
        }

        return res;
    }
};