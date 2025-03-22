class Solution {
public:
    double separateSquares(vector<vector<int>>& v) {
        vector<pair<int, int>> v1;
        for (auto &sq : v) {
            int y1 = sq[1], y2 = sq[1] + sq[2];
            v1.push_back({y1, sq[2]});
            v1.push_back({y2, -sq[2]});
        }
        
        sort(v1.begin(), v1.end());
        
        double total = 0, curr = 0, pv = 0;
        for (auto &[y, width] : v1) 
            total += curr * (y - pv), curr += width, pv = y;
        
        double half_area = total / 2.0;
        curr = 0, pv = 0, total = 0;
        
        for (auto &[y, width] : v1) {
            double next_area = total + curr * (y - pv);
            if (next_area >= half_area)  
                return pv + (half_area - total) / curr;
            total = next_area, curr += width, pv = y;
        }
        return pv;
    }
};