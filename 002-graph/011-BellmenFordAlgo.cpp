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
int main(){
    int N=6,m=7;
    vector<Node>edges;
    edges.push_back(Node(0,1,5));
    edges.push_back(Node(1,2,-2));
    edges.push_back(Node(1,5,-3));
    edges.push_back(Node(2,4,3));
    edges.push_back(Node(3,2,6));
    edges.push_back(Node(3,4,-2));
    edges.push_back(Node(5,3,1));

    int src=0;
    int inf=100000;
    vector<int>sdist_fromSrc(N,inf);
    sdist_fromSrc[src]=0;
    for(int i=1;i<=N-1;i++){
        for(auto it:edges){
            if(sdist_fromSrc[it.u]+it.wt<sdist_fromSrc[it.v]){
                sdist_fromSrc[it.v]=sdist_fromSrc[it.u]+it.wt;
            }
        }
    }

    int fl=0;
    // for(auto it:edges){
    //     if(sdist_fromSrc[it.u]+it.wt<sdist_fromSrc[it.v]){
    //         cout<<-1;
    //         fl=1;
    //         break;
    //     }
    // }
    if(!fl){
        for(int i=0;i<N;i++){
            cout<<sdist_fromSrc[i]<<"--";
        }
    }
}