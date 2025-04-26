class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashMap[nums[i]]) {
                return true;
            }
            hashMap[nums[i]] = true;
        }
        return false;
    }
};