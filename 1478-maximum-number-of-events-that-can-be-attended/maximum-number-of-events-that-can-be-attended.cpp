class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        int n = events.size();
        int pos = 0;
        int time = 1;
        int attended = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        while(pos<n || !minHeap.empty()) {

            if(minHeap.empty())
                time = max(time, events[pos][0]);

            while(pos<n && events[pos][0] == time) {
                minHeap.push(events[pos][1]);
                pos++;
            }

            while(!minHeap.empty() && minHeap.top() < time) {
                minHeap.pop();
            }

            if(!minHeap.empty()) {
                minHeap.pop();
                attended++;
            }

            time++;
        }

        return attended;
    }
};