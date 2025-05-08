class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        unordered_map<int,unordered_map<int,int>> ourmap;
        for(auto it:edges) {
            if(ourmap[it[0]].find(it[1])==ourmap[it[0]].end()) {
                ourmap[it[0]][it[1]]=it[2];
                ourmap[it[1]][it[0]]=it[2];
            }
            else {
                ourmap[it[0]][it[1]] = min(ourmap[it[0]][it[1]], it[2]);
                ourmap[it[1]][it[0]] = min(ourmap[it[1]][it[0]], it[2]);
            }
        }
        //min pq of cost, time, node, parent
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        vector<int> times(passingFees.size(),INT_MAX);
        minHeap.push({passingFees[0], 0, 0, -1});
        while(minHeap.size()) {
            int cost = minHeap.top()[0];
            int time = minHeap.top()[1];
            int node = minHeap.top()[2];
            int parent = minHeap.top()[3];
            minHeap.pop();
            if(node==(passingFees.size()-1)) return cost;
            for(auto it : ourmap[node]) {
                if(it.first==parent 
                || ((time + it.second) > maxTime)
                || times[it.first]<=(time+it.second)) continue;
                times[it.first] = (time+it.second);
                minHeap.push({cost+passingFees[it.first], time + it.second, it.first, node});
            }
        }
        return -1;
    }
};