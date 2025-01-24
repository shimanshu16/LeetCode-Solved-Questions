class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](const vector<int>&x , const vector<int >&y ){
            return x[1]<y[1];
        }
        );
        int k=0 , c=1;
        for(int i=1;i<n;i++){
            if(points[i][0] > points[k][1]){
                c++;
                k=i;
            }
            
        }
        return c;
    }
};