#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int>bfsTrav(int V,vector<int>adj[]){
            vector<int>bfs;
            vector<int>Vis(V,0);
            queue<int>q;
            
            // for(int i=0;i<6;i++){
            //     for(auto it:adj[i]){
            //         cout<<"frm func-"<<it<<"==";
            //     }
            //     cout<<endl;
            // }
            q.push(1);
            Vis[1]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it:adj[node]){
                    if(!Vis[it]){
                        q.push(it);
                        Vis[it]=1;
                    }
                    
                }
            }
            return bfs;
        }
};
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int>adj[6];
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,4);
    // addEdge(adj,2,1);
    // addEdge(adj,3,1);
    // addEdge(adj,4,1);
    // addEdge(adj,4,2);
    // addEdge(adj,5,1);


    // vector<int>sM(7,0);
    // for(auto amartya:sM){
    //     cout<<amartya<<"--";
    // }
    // cout<<endl;
    // cout<<"sM[3]"<<sM[3]<<endl;
    
    for(int i=1;i<6;++i){
        for(auto it:adj[i]){
             cout<<it<<"==";
        }
       cout<<endl;
    }

    Solution s1;
    vector<int>bfsArr=s1.bfsTrav(5,adj);
    
    for(auto &sm:bfsArr){
        cout<<sm<<"----";
    }
}