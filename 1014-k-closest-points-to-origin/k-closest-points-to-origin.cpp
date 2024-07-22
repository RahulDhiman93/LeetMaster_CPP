class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<double, vector<double>, greater<double>> pq;
        unordered_map<double, vector<vector<int>>> umap;
        for (vector<int> point : points) {
            double dist = (double) point[0] * point[0] + point[1] * point[1];
            umap[dist].push_back(point);
            pq.push(dist);
        }
        vector<vector<int>> res;
        while(k) {
            for(vector<int> point: umap[pq.top()]) {
                res.push_back(point);
                pq.pop();
                k--;
            }
        }
        return res;
    }
};