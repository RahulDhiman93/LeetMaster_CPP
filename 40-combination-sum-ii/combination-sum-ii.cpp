class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        helper(candidates, {}, 0, target, res);
        return res;
    }
private:
    void helper(vector<int>& nums, vector<int> subset, int n, int t, vector<vector<int>>& res) {
        if(t==0) {
            res.push_back(subset);
            return;
        }
        if(t<0 || n >= nums.size()) return;

        for(int i=n; i<nums.size(); ++i) {
            if(i>n && nums[i] == nums[i-1]) {
                continue;
            }
            subset.push_back(nums[i]);
            helper(nums, subset, i+1, t-nums[i], res);
            subset.pop_back();
        }
    }
};