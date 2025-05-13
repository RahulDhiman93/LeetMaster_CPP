class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n <=1 && edges.empty()) return true;
        if (edges.empty()) return false;

        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;

        for (int i = 0; i < n; i++) {
            graph[i] = {};
        }

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        bool res = dfs(graph, visited, 0, -1);

        return res && (visited.size() == n);
    }

private:
    bool dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int key, int prev) {
        if (visited.contains(key))
            return false;
        
        if (graph[key].empty())
            return true;
        
        visited.insert(key);
        for (int value: graph[key]) {
            if (value == prev)
                continue;
            
            if (!dfs(graph, visited, value, key))
                return false;
        }
        return true;
    }
};