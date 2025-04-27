class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            hmap[nums[i]]++;
        }

        vector<vector<int>> validator(nums.size() + 1);

        for(const auto& pair : hmap) {
            validator[pair.second].push_back(pair.first);
        }

        vector<int> res;
        for(int j = n; j >= 0; j--) {
            if (res.size() >= k)
                break;
            
            vector<int> position = validator[j];
            for(int l = 0; l < position.size(); l++) {
                if (res.size() >= k) 
                    break;
                
                res.push_back(position[l]);
            }
        }

        return res;
    }
};