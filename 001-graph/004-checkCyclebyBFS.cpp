#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        bool checkCycle(int s,int V,vector<int>adj[],vector<int>&visited){
            queue<pair<int,int>>q;
            q.push({1,-1});
            visited[1]=1;
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(auto it:adj[node]){
                    if(!visited[it]){
                        q.push({it,node});
                        visited[it]=1;
                    }
                    else if(parent !=it){
                        cout<<"parent: "<<parent<<" node: "<<it<<endl;
                        return true;
                    }
                }
            }
            return false;
        }
    public:
        bool isCycle(int V,vector<int>adj[]){
            vector<int>vis(V,0);
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    if(checkCycle(i,V,adj,vis)){
                        return true;
                    }
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
    vector<int>adjList[8];
    // addEdge(adjList,1,5);
    addEdge(adjList,1,6);
    // addEdge(adjList,2,4);
    addEdge(adjList,5,7);
    addEdge(adjList,2,3);
    addEdge(adjList,7,2);
    addEdge(adjList,4,5);
    addEdge(adjList,1,4);
    addEdge(adjList,5,6);

    for(int i=0;i<8;i++){
        for(auto it:adjList[i]){
            cout<<it<<"--";
        }
        cout<<endl;
    }
    Solution s1;
    if(s1.isCycle(8,adjList)){
        cout<<"Cycle exist"<<endl;
    }else{
        cout<<"Acyclic"<<endl;
    }
}