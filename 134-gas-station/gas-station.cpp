class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0, costSum = 0;
        int total = 0, res = 0;   

        for(int i = 0; i < gas.size(); ++i) {
            gasSum += gas[i];
            costSum += cost[i];

            if (total == 0) {
                res = i;
            }
            total += (gas[i] - cost[i]);
            if (total < 0) {
                total = 0;
            }
        }

        if (gasSum < costSum) return -1;
        return total >= 0 ? res : -1;
    }
};