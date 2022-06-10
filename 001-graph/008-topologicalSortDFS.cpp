#include<bits/stdc++.h>
using namespace std;

class Solution{
//     void findTopoSort(int node, vector < int > & vis, stack < int > & st, vector < int > adj[]) {
//     vis[node] = 1;

//     for (auto it: adj[node]) {
//       if (!vis[it]) {
//         findTopoSort(it, vis, st, adj);
//       }
//     }
//     cout<<"stack pushing: "<<node<<endl;
//     st.push(node);
//   }
//   public:
//     vector < int > topoDFS(int N, vector < int > adj[]) {
//       stack < int > st;
//       vector < int > vis(N, 0);
//       for (int i = 1; i < N; i++) {
//         if (vis[i] == 0) {
//           findTopoSort(i, vis, st, adj);
//         }
//       }
//       vector < int > topo;
//       while (!st.empty()) {
//         topo.push_back(st.top());
//         st.pop();
//       }
//       return topo;

//     }
    public:
        vector<int>topoDFS(int V,vector<int>adj[]){
            stack<int>st;
            vector<int>indegree(V,0);
            for(int i=1;i<V;i++){
                for(auto it:adj[i]){
                    indegree[it]++;
                }
            }
            for(int j=1;j<V;j++){
                if(indegree[j]==0){
                    st.push(j);
                }
            }
            vector<int>topo;
            while(!st.empty()){
                int node=st.top();
                st.pop();
                topo.push_back(node);
                for(auto it:adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        st.push(it);
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
    addEdge(adj,5,4);
    addEdge(adj,5,1);

    Solution obj;
    vector<int>topologicalDFS=obj.topoDFS(V,adj);
    for(auto it:topologicalDFS){
        cout<<it<<"--";
    }
    cout<<endl;
}