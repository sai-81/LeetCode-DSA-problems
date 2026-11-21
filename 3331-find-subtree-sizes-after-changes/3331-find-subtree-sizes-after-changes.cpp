class Solution {
public:
   vector<int>orgParent;
   int dfs(int i,vector<vector<int>>&adj,vector<int>&ans){
      int n=ans.size();
      if(i>=n) return 0;
      int sum=1;
      for(auto u:adj[i]){
       sum+=dfs(u,adj,ans);
      }
      return ans[i]=sum;
      
   }
   void buildNewTree(int u,vector<vector<int>>&newAdj,const vector<vector<int>>&orgAdj,vector<int>&lastSeen,const string &s){
    int charIdx=s[u]-'a';
    int prev=lastSeen[charIdx];
    if(u!=0){
        if(prev!=-1){
            newAdj[prev].push_back(u);
        }else{
            newAdj[orgParent[u]].push_back(u);
        }
    }
    lastSeen[charIdx]=u;
    for(auto v:orgAdj[u]){
       buildNewTree(v,newAdj,orgAdj,lastSeen,s);
    }
    lastSeen[charIdx]=prev;
   }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        orgParent=parent;
        vector<vector<int>>orgAdj(n);
        for(int i=1;i<n;i++){
            orgAdj[parent[i]].push_back(i);
        }
        vector<int>lastSeen(26,-1);
        vector<vector<int>>newAdj(n);
        buildNewTree(0,newAdj,orgAdj,lastSeen,s);
        vector<int>ans(n,0);
        dfs(0,newAdj,ans);
        return ans;
    }
};