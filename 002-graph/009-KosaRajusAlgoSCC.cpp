#include<bits/stdc++.h>
using namespace std;

// for toplogical sorting----------------->
void dfs(int node,stack<int>&st,vector<int>adj[],vector<int>&Vis){
    Vis[node]=1;
    for(auto it:adj[node]){
        if(!Vis[it]){
            dfs(it,st,adj,Vis);
        }
    }
    st.push(node);
}

// from the transpose Adjacency List Showing the elements---->
void revDFS(int node,vector<int>transpose[],vector<int>&Vis){
    cout<<node<<" ";
    Vis[node]=1;
    for(auto it:transpose[node]){
        if(!Vis[it]){
            revDFS(it,transpose,Vis);
        }
    }
}
// ================================================

void addEdge(vector<int>adj[],int x,int y){
    adj[x].push_back(y);
}
int main(){
    int V=7;
    vector<int>adj[V];
    addEdge(adj,1,3);
    addEdge(adj,2,1);
    addEdge(adj,3,2);
    addEdge(adj,3,5);
    addEdge(adj,4,6);
    addEdge(adj,5,4);
    addEdge(adj,6,5);

    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            cout<<it<<"==";
        }
        cout<<endl;
    }
    vector<int>Vis(V,0);
    stack<int>st;
    for(int i=1;i<V;i++){
        if(!Vis[i]){
            dfs(i,st,adj,Vis);
        }
    }

    vector<int>transpose[V];
    for(int j=1;j<V;j++){
        Vis[j]=0;
        for(auto it:adj[j]){
            transpose[it].push_back(j);
        }
    }
    for(int i=0;i<V;i++){
        for(auto it:transpose[i]){
            cout<<it<<"<-";
        }
        cout<<endl;
    }

    // ====================
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!Vis[node]){
            cout<<"SCC: ";
            revDFS(node,transpose,Vis);
            cout<<endl;
        }
    }

}