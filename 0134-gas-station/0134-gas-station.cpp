class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        for (int i = 0; i < gas.size (); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if (total_cost > total_gas)
            return -1;
        int start = 0, curfuel = 0;
        for (int i = 0; i < gas.size (); i++) {
            if (curfuel < 0) {
                curfuel = 0;
                start = i;
            }
            curfuel += gas[i] - cost[i];
        }
        return start;
    }
};