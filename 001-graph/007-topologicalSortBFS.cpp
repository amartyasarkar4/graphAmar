#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int>topoBFS(int V,vector<int>adj[]){
            queue<int>q;
            vector<int>indegree(V,0);
            for(int i=1;i<V;i++){
                for(auto it:adj[i]){
                    indegree[it]++;
                }
            }
            for(int j=1;j<V;j++){
                if(indegree[j]==0){
                    q.push(j);
                }
            }
            vector<int>topo;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                topo.push_back(node);
                for(auto it:adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
            }
            return topo;
        }
};

void addEdge(vector<int>adj[],int x,int y){
    adj[x].push_back(y);
}
int main(){
    int V=6;
    vector<int>adj[V];
    addEdge(adj,1,2);
    addEdge(adj,3,2);
    addEdge(adj,3,4);
    addEdge(adj,4,2);
    addEdge(adj,4,5);
    addEdge(adj,5,1);

    Solution obj;
    vector<int>topologicalBFS=obj.topoBFS(V,adj);
    for(auto it:topologicalBFS){
        cout<<it<<"--";
    }
    cout<<endl;


}