class Solution {
public:
    void dfs(vector<set<int>>& adj,int sv,int& mn,vector<int>& vis){
        vis[sv]=1;
        mn=min(mn,sv);
        for(auto v: adj[sv]){
            if(!vis[v]){
                dfs(adj,v,mn,vis);
            }
        }
    }
    int findmin(vector<set<int>>& adj,int c){
        int mn=c;
        vector<int> vis(26);
        dfs(adj,c,mn,vis);
        return mn;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n =s1.size();
        vector<set<int>> adj(26);
        for(int i=0;i<n;i++){
            int u=s1[i]-'a',v=s2[i]-'a';
            adj[u].insert(v);
            adj[v].insert(u);

        }//O(n)
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            int c=baseStr[i]-'a';
            int c1=findmin(adj,c);//O(26)
            ans += (c1+'a');
        }//O(m)
        return ans;
        
    }
};