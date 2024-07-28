class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {};
        helper(nums, {}, 0, res);
        return res;
    }
private:
    void helper(vector<int>& nums, vector<int> subset, int n, vector<vector<int>>& res) {
        //Base case for backtracking
        if(n >= nums.size()) {
            vector<int> temp = subset;
            res.push_back(temp);
            return;
        }

        //Including the number
        subset.push_back(nums[n]);
        helper(nums, subset, n+1, res);

        //Excluding the number
        subset.pop_back();
        helper(nums, subset, n+1, res);
    }
};