#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int>dfs(int V,vector<int>adj[]){
            vector<int>dfsArr;
            vector<int>Vis(V,0);
            stack<int>st;
            st.push(1);
            Vis[1]=1;
            while(!st.empty()){
                int node=st.top();
                st.pop();
                dfsArr.push_back(node);
                for(auto it:adj[node]){
                    if(!Vis[it]){
                        st.push(it);
                        Vis[it]=1;
                    }
                }
            }
            return dfsArr;
        }
};

void addEdge(vector<int>adj[],int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}
int main(){
    vector<int>adj[8];
    addEdge(adj,1,2);
    addEdge(adj,1,6);
    // addEdge(adj,2,4);
    addEdge(adj,2,7);
    addEdge(adj,4,3);
    addEdge(adj,7,3);
    addEdge(adj,4,5);
    // addEdge(adj,7,5);
    addEdge(adj,5,6);

    for(int i=0;i<8;i++){
        for(auto it:adj[i]){
            cout<<it<<"--";
        }
        cout<<endl;
    }
    Solution s3;
    vector<int>dfsV=s3.dfs(8,adj);

    for(auto a:dfsV){
        cout<<":"<<a<<"--";
    }
    cout<<endl;
}