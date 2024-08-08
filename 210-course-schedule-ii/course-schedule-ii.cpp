class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        unordered_map<int, vector<int>> umap;
        set<int> visited;
        set<int> repeated;
        vector<int> res;

        for (int i = 0; i < m; ++i) {
            umap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i < numCourses; ++i) {
            if(!dfs(umap, visited, repeated, res, i))
                return {};
        }

        return res;
    }

private:
    bool dfs(unordered_map<int, vector<int>>& umap, set<int>& visited,
             set<int>& repeated, vector<int>& res, int curr) {
        if(repeated.contains(curr))
            return false;
        if(visited.contains(curr))
            return true;

        repeated.insert(curr);

        for(int pre : umap[curr]) {
            if(!dfs(umap, visited, repeated, res, pre))
                return false;
        }

        repeated.erase(curr);
        visited.insert(curr);
        res.push_back(curr);
        return true;
    }
};