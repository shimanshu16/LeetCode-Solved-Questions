class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& vis,int k,int i){
        if(vis[i]!=0){
            return;
        }
        vis[i]=k;
        for(int j=0;j<adj[i].size();j++){
            dfs(adj,vis,k,adj[i][j]);
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            
                if(arr[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        vector<int> vis(n,0);
        int k=1;
        int i=0;
        dfs(adj,vis,k,i);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(adj,vis,k,i);
                k++;
            }
            else{
                continue;
            }
        }
        return k;
    }
};