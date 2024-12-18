class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0, costSum = 0;
        vector<int> diff(gas.size(), 0);

        for (int i = 0; i < gas.size(); ++i) {
            gasSum += gas[i];
            costSum += cost[i];
            diff[i] = gas[i] - cost[i];
        }

        if (gasSum < costSum) return -1;

        int total = 0, res = 0;        
        for(int i = 0; i < diff.size(); ++i) {
            if (total == 0) {
                res = i;
            }
            total += diff[i];
            if (total < 0) {
                total = 0;
            }
        }

        return total >= 0 ? res : -1;
    }
};