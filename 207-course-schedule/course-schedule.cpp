class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;

        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;

        for(int i = 0; i < numCourses; ++i) {
            graph[i] = {};
        }

        for(int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i < numCourses; ++i) {
            if (!dfs(graph, visited, i))
                return false;
        }

        return true;
    }

private:
    bool dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int key) {
        if (visited.contains(key))
            return false;
        
        if (graph[key].empty())
            return true;
        
        visited.insert(key);
        for(int value: graph[key]) {
            if (!dfs(graph, visited, value))
                return false;
        }
        visited.erase(key);
        graph[key] = {};
        return true;
    }
};