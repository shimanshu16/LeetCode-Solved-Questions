class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaOfRect1 = (ay2 - ay1) * (ax2 - ax1);
        int areaOfRect2 = (by2 - by1) * (bx2 - bx1);

        int left = max(ax1, bx1);
        int bottom = max(ay1, by1);
        int right = min(ax2, bx2);
        int top = min(ay2, by2);

        int xOverlap = right - left;
        int yOverlap = top - bottom;
        int areaOfOverlap = 0;
        if(xOverlap > 0 && yOverlap > 0)
            areaOfOverlap = xOverlap * yOverlap;

        int area = areaOfRect1 + areaOfRect2 - areaOfOverlap;
        return area;
    }
};