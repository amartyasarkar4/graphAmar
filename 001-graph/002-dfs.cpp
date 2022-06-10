#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
        void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&storeDfs){
            storeDfs.push_back(node);
            vis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it])dfs(it,vis,adj,storeDfs);
            }
        }
    public:
        vector<int>dfsTrav(int V,vector<int>adj[]){
            vector<int>storeDfs;
            vector<int>Vis(V+1,0);
            for(int i=1;i<=V;i++){
                if(!Vis[i])dfs(i,Vis,adj,storeDfs);
            }
            return storeDfs;
        }
};
void addEdge(vector<int>adj[],int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}
int main(){
    vector<int>adjList[6];
    addEdge(adjList,1,2);
    addEdge(adjList,1,3);
    addEdge(adjList,1,4);
    addEdge(adjList,1,5);
    addEdge(adjList,4,2);

    for(int i=0;i<6;i++){
        for(auto &it:adjList[i]){
            cout<<it<<"=";
        }
        cout<<endl;
    }
    Solution s2;
    vector<int>dfsView=s2.dfsTrav(5,adjList);
    for(auto it:dfsView){
        cout<<it<<"+";
    }
}