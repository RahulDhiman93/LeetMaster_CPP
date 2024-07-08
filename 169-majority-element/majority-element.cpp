class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        int maxV = INT_MIN;
        int res;
        for(int i=0;i<nums.size();i++) {
            umap[nums[i]]++;
            if (maxV < umap[nums[i]]) {
                maxV = umap[nums[i]];
                res = nums[i];
            }
        }
        return res;
    }
};