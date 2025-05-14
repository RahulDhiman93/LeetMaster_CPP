class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        if (edges.empty()) return n;

        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;

        for (int i = 0; i < n; ++i) {
            graph[i] = {};
        }

        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited.contains(i)) {
                res++;
                dfs(graph, visited, i);
            }
        }

        return res;
    }

private:    
    void dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int key) {
        if (visited.contains(key))
            return;
        
        visited.insert(key);
        for (int value: graph[key]) {
            dfs(graph, visited, value);
        }
    }
};