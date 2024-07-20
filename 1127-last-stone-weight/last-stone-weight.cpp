class Solution {
private:
    priority_queue<int, vector<int>, less<int>> pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int stone: stones) {
            pq.push(stone);
        }
        while(pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            if(x == y) continue;
            else pq.push(y-x);
        }
        return pq.size() > 0 ? pq.top() : 0;
    }
};