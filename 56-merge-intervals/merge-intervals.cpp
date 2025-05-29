class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        int n = intervals.size(), i = 0;

        while (i < n - 1) {

            if (i + 1 < n && intervals[i][1] < intervals[i + 1][0]) {
                res.push_back(intervals[i]);
                i++;
                continue;
            }

            vector<int> newInterval(2);
            newInterval[0] = INT_MAX;
            newInterval[1] = INT_MIN;
            int j = i;
            while (i + 1 < n && intervals[j][1] >= intervals[i + 1][0]) {
                newInterval[0] = min(newInterval[0],
                                     min(intervals[i][0], intervals[i + 1][0]));
                newInterval[1] = max(newInterval[1],
                                     max(intervals[i + 1][1], intervals[i][1]));
                intervals[j] = newInterval;
                i++;
            }
            if (newInterval[0] != INT_MAX && newInterval[1] != INT_MIN) {
                res.push_back(newInterval);
                i++;
            }
        }

        if (i == n - 1) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};