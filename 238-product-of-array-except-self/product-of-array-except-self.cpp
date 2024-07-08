class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int pre=1;
        int post=1;

        for(int i=0; i<n; i++) {
            res[i] = pre;
            pre *= nums[i];
        }
        for(int j=n-1; j>=0; j--) {
            res[j] *= post;
            post *= nums[j];
        }
        
        return res;
    }
};