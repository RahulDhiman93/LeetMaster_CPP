class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hmap;
        for(int i = 0; i < numbers.size(); ++i) {
            if (hmap.contains(numbers[i])) {
                return {hmap[numbers[i]]+1, i+1};
            }
            hmap[target-numbers[i]] = i; 
        }
        return {};
    }
};