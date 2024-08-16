class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> par;
        vector<int> rank(edges.size() + 1, 1);
        
        for (int i = 0; i <= edges.size(); i++) {
            par.push_back(i);
        }

        for (int i = 0; i < edges.size(); i++) {
            if (!uni(par, rank, edges[i][0], edges[i][1])) {
                return {edges[i][0], edges[i][1]};
            }
        }
        return {};
    }

private:
    int find(vector<int>& par, int n) {
        int p = par[n];
        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool uni(vector<int>& par, vector<int>& rank, int n1, int n2) {
        int p1 = find(par, n1), p2 = find(par, n2);

        if (p1 == p2)
            return false;

        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};