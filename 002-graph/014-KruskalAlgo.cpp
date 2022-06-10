#include<bits/stdc++.h>
using namespace std;

struct Node{
    int u;
    int v;
    int wt;
    Node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};
bool comp(Node a,Node b){
    return a.wt<b.wt;
}
int findParent(int u,vector<int>&parent){
    cout<<"u:"<<u<<endl;
    if(u==parent[u])return u;
    cout<<"parent[u]:"<<parent[u];
    return parent[u] =findParent(parent[u],parent);
}
void unionn(int u,int v,vector<int>&parent,vector<int>&rank){
    cout<<"u:"<<u<<"v:"<<v<<endl;
    u=findParent(u,parent);
    v=findParent(v,parent);
    if(rank[u]<rank[v]){
        cout<<"su:"<<u<<"gv:"<<v<<endl;
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        cout<<"gu:"<<u<<"sv:"<<v<<endl;
        parent[v]=u;
    }else{
        cout<<"Ru:"<<u<<"Rv:"<<v<<endl;
        parent[v]=u;
        rank[u]++;
    }
}
int main(){
    int N=6,m=7;
    vector<Node>edges;
    edges.push_back(Node(0,1,2));
    edges.push_back(Node(0,3,6));
	edges.push_back(Node(1,0,2));
	edges.push_back(Node(1,2,3));
	edges.push_back(Node(1,3,8));
	edges.push_back(Node(1,4,5));
	edges.push_back(Node(2,1,3));
	edges.push_back(Node(2,4,7));
	edges.push_back(Node(3,0,6));
	edges.push_back(Node(3,1,8));
	edges.push_back(Node(4,1,5));
	edges.push_back(Node(4,2,7));

    // for(auto it:edges){
    //     cout<<it.u<<":"<<it.v<<"="<<it.wt<<endl;
    // }
    
    sort(edges.begin(),edges.end(),comp);
    cout<<"after sorting:"<<endl;
    for(auto it:edges){
        cout<<it.u<<":"<<it.v<<"="<<it.wt<<endl;
    }

    vector<int>parent(N);
    for(int i=0;i<N;i++){
        parent[i]=i;
    }
    vector<int>rank(N,0);

    int cost=0;
    vector<pair<int,int>>mst;
    for(auto it:edges){
        if(findParent(it.u,parent)!=findParent(it.v,parent)){
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,parent,rank);
        }
    }
    cout<<cost<<endl;
    for(auto it:mst){
        cout<<it.first<<"-"<<it.second<<endl;
    }
}