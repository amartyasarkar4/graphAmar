#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        bool checkCycle(int node,vector<int>adj[],int vis[],int dfsVis[]){
            vis[node]=1;
            dfsVis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it]){
                    cout<<"it: "<<it<<endl;
                    if(checkCycle(it,adj,vis,dfsVis)){
                        return true;
                    }
                }else if(dfsVis[it]){
                    cout<<it<<endl;
                    return true;
                }
            }
            dfsVis[node]=0;
            return false;
        }
        bool mycheckCycle(int node,vector<int>adj[],vector<int>&vis,vector<int>&dfsVis){
            vis[node]=1;
            dfsVis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it]){
                    cout<<"it: "<<it<<endl;
                    if(mycheckCycle(it,adj,vis,dfsVis)){
                        return true;
                    }
                }else if(dfsVis[it]){
                    cout<<it<<endl;
                    return true;
                }
            }
            cout<<node<<"dfsVis=0"<<endl;
            dfsVis[node]=0;
            return false;
        }
    public:
        bool isCyclic(int V,vector<int>adj[]){
            // int vis[V];
            // int dfsVis[V];
            // memset(vis,0,sizeof vis);
            // memset(dfsVis,0,sizeof dfsVis);
            vector<int>vis(V,0);
            vector<int>dfsVis(V,0);
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    if(mycheckCycle(i,adj,vis,dfsVis)){
                        return true;
                    }
                }
            }
            return false;
        }
};
void addEdge(vector<int>adj[],int x,int y){
    adj[x].push_back(y);
    // adj[y].push_back(x);
}
int main(){
    int V=6;
    vector<int>adjList[V];
    // addEdge(adjList,1,6);
    // addEdge(adjList,7,2);
    // addEdge(adjList,5,4);
    // addEdge(adjList,2,3);
    // addEdge(adjList,5,7);
    // // addEdge(adjList,7,4);
    // addEdge(adjList,5,6);


    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 5);
    addEdge(adjList, 2, 3);
    // addEdge(adjList, 3, 4);
    addEdge(adjList, 5, 1);
    addEdge(adjList, 4, 1);

    for(int i=0;i<V;i++){
        for(auto it:adjList[i]){
            cout<<it<<"--";
        }
        cout<<endl;
    }

    Solution s1;
    if(s1.isCyclic(V,adjList)){
        cout<<"Cycle is Detected."<<endl;
    }else{
        cout<<"No cycle"<<endl;
    }
}