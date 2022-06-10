#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        bool checkForCycle(int node,int parent,vector<int>adj[],vector<int>&Vis){
            Vis[node]=1;
            for(auto it:adj[node]){
                if(!Vis[it]){
                    if(checkForCycle(it,node,adj,Vis))return true;
                }
                else if(parent!=it){
                    cout<<"parent: "<<parent<<" node: "<<it<<endl;
                    return true;
                }
            }
            return false;
        }
    public:
        bool isCyclic(int V,vector<int>adj[]){
            vector<int>Vis(V,0);
            for(int i=0;i<V;i++){
                if(!Vis[i]){
                    if(checkForCycle(i,-1,adj,Vis))return true;
                }
            }
            return false;
        }
};

void addEdge(vector<int>adj[],int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}
int main(){
    vector<int> adjList[8];
    addEdge(adjList,1,6);
    addEdge(adjList,7,2);
    addEdge(adjList,5,4);
    addEdge(adjList,2,3);
    addEdge(adjList,5,7);
    addEdge(adjList,7,4);
    addEdge(adjList,5,6);

    for(int i=0;i<8;i++){
        for(auto it:adjList[i]){
            cout<<it<<"--";
        }
        cout<<endl;
    }
    Solution s1;
    if(s1.isCyclic(8,adjList)){
        cout<<"Cycle Exist"<<endl;
    }else{
        cout<<"acyclic"<<endl;
    }

}