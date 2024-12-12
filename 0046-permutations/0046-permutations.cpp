class Solution {
public:
     vector<vector<int>>v2;
    void per(vector<int>& v,int l,int h){
       
        if(l==h){
            v2.push_back(v);
        }else{
            for(int i=l;i<h;i++){
                swap(v[l],v[i]);
                per(v,l+1,h);
                swap(v[l],v[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       per(nums,0,nums.size());
        return v2;
    }
};