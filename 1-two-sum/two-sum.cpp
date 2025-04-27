class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;

        for(int i = 0; i < nums.size(); ++i) {
            if (hashMap.contains(nums[i]))
                return {i, hashMap[nums[i]]};
            
            hashMap[target-nums[i]] = i;
        }

        return {};
    }
};