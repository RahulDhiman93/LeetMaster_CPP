class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        for(int num: nums) {
            pq.push(num);
        }
        k--;
        while(k){
            pq.pop();
            k--;
        } 
        return pq.top();
    }
};