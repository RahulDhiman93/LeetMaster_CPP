class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq;

        for (const auto& pair: prerequisites) {
            prereq[pair[0]].push_back(pair[1]);
        }

        unordered_set<int> visited;
        unordered_set<int> cycle;

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, prereq, visited, cycle))
                return false;
        }

        return true;
    }

private:
    bool dfs(int curr, unordered_map<int, vector<int>>& prereq, unordered_set<int>& visited, unordered_set<int>& cycle) {

        if (cycle.contains(curr))
            return false;
        
        if (visited.contains(curr))
            return true;
        
        cycle.insert(curr);
        for (int pre: prereq[curr]) {
            if (!dfs(pre, prereq, visited, cycle)) {
                return false;
            }
        }
        cycle.erase(curr);
        visited.insert(curr);
        return true;
    }
};