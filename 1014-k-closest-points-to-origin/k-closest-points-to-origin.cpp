class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (vector<int> p : points) {
            pq.push({(p[0]*p[0]+p[1]*p[1]), {p[0], p[1]}});
            if (pq.size()>k) pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            vector<int> point = {pq.top().second.first, pq.top().second.second};
            res.push_back(point);
            pq.pop();
        }
        return res;
    }
};