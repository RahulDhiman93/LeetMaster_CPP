class Solution {
public:
    int numDistinct(string s, string t) {
        map<pair<int, int>, int> cache;
        int m = s.size();
        int n = t.size();
        return dfs(cache, 0, 0, m, n, s, t);
    }
private:
    int dfs(map<pair<int, int>, int>& cache, int i, int j, int& m, int& n, string& s, string& t) {
        if (j == n)
            return 1;
        if (i == m)
            return 0;
        if (cache.contains({i, j}))
            return cache[{i, j}];
        
        if (s[i] == t[j]) {
            cache[{i, j}] = dfs(cache, i+1, j+1, m, n, s, t) + dfs(cache, i+1, j, m, n, s, t);
        } else {
            cache[{i, j}] = dfs(cache, i+1, j, m, n, s, t);
        }

        return cache[{i, j}];
    }
};