class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i=0; i<nums.size(); i++) {
            if (umap.contains(nums[i])) {
                vector<int> res = {i, umap[nums[i]]};
                return res;
            }
            umap[target-nums[i]] = i;
        }
        return {};
    }
};