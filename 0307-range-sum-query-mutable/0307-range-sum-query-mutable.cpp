#pragma GCC optimize("03")
static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();
class NumArray {
    vector<int> seg;
    int n;
public:
    
    void built(int i, int l,int h, vector<int>& v)
    {
       
        if(l==h) {seg[i]=v[l]; return ;}
        int m=(l+h)/2;
        built(i*2+1,l,m,v);
        built(i*2+2,m+1,h,v);
        seg[i]=seg[i*2+1]+seg[i*2+2];
    }
    void make(int i,int l,int h,int ind,int val)
    {
        if(l==h)
        {
            seg[i]=val;
            return;
        }
        int m=(l+h)/2;
        if(ind<=m)
        {
            make(i*2+1,l,m,ind,val);
        }
        else make(i*2+2,m+1,h,ind,val);
        seg[i]=seg[i*2+1]+seg[i*2+2];
        return ;
    }
    int solve(int i,int l,int h,int lt,int rt)
    {
        if(lt>h||rt<l) return 0;
        if(lt<=l&&rt>=h) return seg[i];
        int m=(l+h)/2;
        int a=0;
        a=solve(i*2+1,l,m,lt,rt);
        a+=solve(i*2+2,m+1,h,lt,rt);
        return a;
    }
    NumArray(vector<int>& nums) {
         n=nums.size();
        seg.resize(4*nums.size(),0);
        built(0,0,nums.size()-1,nums);
    }
    
    void update(int index, int val) {
        make(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return solve(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */