class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = INT_MAX;
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break;
            }

            int m = (l+r)/2;
            res = min(res, nums[m]);
            if (nums[m] >= nums[l]) {
                l = m+1;
            } else {
                r = m-1;
            }      
        }

        return res;
    }
};