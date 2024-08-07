class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0)
            return true;
        unordered_map<int, vector<int>> umap;
        int m = prerequisites.size();
        int n = prerequisites[0].size();
        set<int> visited;

        for (int i = 0; i < m; ++i) {
            umap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if(!dfs(umap, visited, i))
                return false;
        }
        return true;
    }

private:
    bool dfs(unordered_map<int, vector<int>>& umap, set<int>& visited, int curr) {
        if (visited.contains(curr))
            return false;
        if (umap[curr].empty())
            return true;

        visited.insert(curr);
        for (int pre : umap[curr]) {
            if (!dfs(umap, visited, pre))
                return false;
        }
        visited.erase(curr);
        umap[curr].clear();
        return true;
    }
};