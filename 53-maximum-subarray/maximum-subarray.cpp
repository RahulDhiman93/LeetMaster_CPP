class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], curr = 0;

        for(int n: nums) {
            if (curr < 0)
                curr = 0;
            
            curr += n;
            res = max(res, curr);
        }

        return res;
    }
};