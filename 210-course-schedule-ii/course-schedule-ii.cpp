class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preReq;

        for (const auto& pair : prerequisites) {
            preReq[pair[0]].push_back(pair[1]);
        }

        vector<int> output;
        unordered_set<int> visited;
        unordered_set<int> cycle;

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, preReq, visited, cycle, output))
                return {};
        }
        return output;
    }

private:
    bool dfs(int curr, unordered_map<int, vector<int>>& preReq,
             unordered_set<int>& visited, unordered_set<int>& cycle,
             vector<int>& output) {

        if (cycle.contains(curr))
            return false;
        
        if (visited.contains(curr))
            return true;
        
        cycle.insert(curr);
        for (int pre: preReq[curr]) {
            if (!dfs(pre, preReq, visited, cycle, output))
                return false;
        }
        cycle.erase(curr);
        visited.insert(curr);
        output.push_back(curr);
        return true;
    }
};