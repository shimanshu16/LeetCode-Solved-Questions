class Solution {
public:
bool cycle(vector<vector<int>> &adj,vector<int> &vis,vector<int> &path,int node){
    vis[node]=true;
    path[node]=true;
    for(auto i:adj[node]){
        if(!vis[i]){
            if(cycle(adj,vis,path,i))return true;
        }
        else if(path[i]){
            return true;
        }
    }
    path[node]=false;
    return false;
}
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            int f=(1001*n+nums[i]+i)%n;
            if(f!=i && nums[i]*nums[f]>0)
            adj[i].push_back(f);
        }
        vector<int> vis(n,false);
        vector<int> path(n,false);
    
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cycle(adj,vis,path,i))return true;
            }
        }
        return false;
    }
};