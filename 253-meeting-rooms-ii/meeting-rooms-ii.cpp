class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        for(auto& interval: intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int res = 0, count = 0;
        int s = 0, e = 0;

        while(s < intervals.size()) {
            if (start[s] < end[e]) {
                s++;
                count++;
            } else {
                e++;
                count--;
            }
            res = max(res, count);
        }

        return res;
    }
};