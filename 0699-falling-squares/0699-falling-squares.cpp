class Solution {
public:
    vector<int>seg;
    vector<int>lazy;
    int n;

    void updateRange(int node, int start, int end, int left, int right, int val){
        if(lazy[node]){
            seg[node] =lazy[node];
            if(start!=end){
                lazy[2*node+1] = lazy[node];
                lazy[2*node+2] =lazy[node];
            }
            lazy[node]=0;
        }
        if(right<start || left>end || start>end) return;

        if(left<=start && right>=end){
            seg[node] =val;
            if(start!=end){
                lazy[2*node+2] = val;
                lazy[2*node+1] = val;
            }
            return;
        }

        int mid = start+(end-start)/2;
        updateRange(2*node+1,start,mid,left,right,val);
        updateRange(2*node+2,mid+1,end,left,right,val);

        seg[node]= max(seg[2*node+1],seg[2*node+2]);

    }

    int queryRange(int node, int start, int end, int left, int right){
        if(start>end || start>right || end <left)return 0;

        if(lazy[node]!=0){
            seg[node] = lazy[node];
            if(start!=end){
                lazy[2*node+1]=lazy[node];
                lazy[2*node+2] = lazy[node];
            }
            lazy[node]=0;
        }

        if(left<=start && end<=right) return seg[node];

        int mid = start+(end-start)/2;

        int q1 = queryRange(2*node+1,start,mid,left,right);
        int q2 = queryRange(2*node+2,mid+1,end,left,right);

        return max(q1,q2);
    }
 
    vector<int> fallingSquares(vector<vector<int>>& positions) {
 
        vector<int> ac;
        for(int i=0;i<positions.size();i++){
            ac.push_back(positions[i][0]);
            ac.push_back(positions[i][1]+positions[i][0]-1);
        }

        sort(ac.begin(),ac.end());
        ac.erase(unique(ac.begin(),ac.end()), ac.end());

        unordered_map<int, int> coordMap;
        for (int i = 0; i < ac.size(); i++) {
            coordMap[ac[i]] = i;
        }
        n = ac.size();

        seg.resize(4*n,0);
        lazy.resize(4*n,0);

        vector<int>ans;
        int temp =0;

        for(auto& v: positions){
            int hello = queryRange(0,0,n,coordMap[v[0]],coordMap[v[0]+v[1]-1]);
            updateRange(0,0,n,coordMap[v[0]],coordMap[v[0]+v[1]-1],v[1]+hello);            
            ans.push_back(max(temp,queryRange(0,0,n,coordMap[v[0]],coordMap[v[0]+v[1]-1])));
            temp = max(temp,ans.back());
        }

        return ans;

    }
};  