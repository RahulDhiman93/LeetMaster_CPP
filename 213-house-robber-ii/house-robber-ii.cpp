class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1)
            return nums[0];
        return max(helper(nums, 0, n-2), helper(nums, 1, n-1));
    }
private:
    int helper(vector<int>& nums, int s, int n) {
        int prev = 0;
        int curr = 0;
        int next = 0;
        
        for (int i = s; i <= n; i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        
        return curr;
    }
};