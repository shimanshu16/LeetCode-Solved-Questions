class Solution {
public:
    int X, Y;
    array<int, 2> swapX={0}, swapY={0};
    bool hasX=1, hasY=1;
    bool check(int i, int XY, bool hasXY, array<int, 2>& swapXY, vector<int>& tops, vector<int>& bottoms){
        if (hasXY) {
            if (tops[i]!=XY && bottoms[i]!=XY) 
                return 0;
            else {
                if (tops[i]!=XY) swapXY[0]++;
                if (bottoms[i]!=XY) swapXY[1]++;
            }
        }
        return 1;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        const int n = tops.size();

        int X=tops[0], Y=bottoms[0];

        for (int i=0; i<n; i++) {
            if (hasX) hasX=check(i, X, hasX, swapX, tops, bottoms);
            if (hasY) hasY=check(i, Y, hasY, swapY, tops, bottoms);
            if (!hasX && !hasY) return -1;
        }

        int ans=INT_MAX;
        if (hasX) ans=min(ans, min(swapX[0], swapX[1]));
        if (hasY) ans=min(ans, min(swapY[0], swapY[1]));

        return ans;
    }
};
