class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMul(n);
        vector<int> rightMul(n);

        leftMul[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            leftMul[i] = nums[i] * leftMul[i - 1];
        }

        rightMul[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            rightMul[i] = nums[i] * rightMul[i + 1];
        }

        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            if (i == 0) {
                res[i] = rightMul[1];
            } else if (i == n - 1) {
                res[i] = leftMul[n - 2];
            } else {
                res[i] = rightMul[i + 1] * leftMul[i - 1];
            }
        }

        return res;
    }
};