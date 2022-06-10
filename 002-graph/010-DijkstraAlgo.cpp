#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=6;
    int m=6,source=1;
    vector<pair<int,int>>wG[n];
    wG[1].push_back({2,2});
    wG[1].push_back({4,1});
    wG[2].push_back({1,2});
    wG[2].push_back({5,5});
    wG[2].push_back({3,4});
    wG[3].push_back({2,4});
    wG[3].push_back({4,3});
    wG[3].push_back({5,1});
    wG[4].push_back({1,1});
    wG[4].push_back({3,3});
    wG[5].push_back({2,5});
    wG[5].push_back({3,1});

    for(int i=1;i<n;i++){
        for(auto it:wG[i]){
            cout<<"("<<it.first<<","<<it.second<<") , ";
        }
        cout<<endl;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>sdist_FromSource(n,INT16_MAX);
    pq.push(make_pair(0,source));
    sdist_FromSource[source]=0;
    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        vector<pair<int,int>>::iterator it;
        for(it=wG[prev].begin();it!=wG[prev].end();it++){
            int next=it->first;
            int distoNext=it->second;
            if(sdist_FromSource[next]>sdist_FromSource[prev]+distoNext){
                sdist_FromSource[next]=sdist_FromSource[prev]+distoNext;
                pq.push(make_pair(sdist_FromSource[next],next));
            }
        }
    }
    cout<<"The distances from the source("<<source<<") are: ";
    for(int i=1;i<n;i++){
        cout<<"("<<i<<"): "<<sdist_FromSource[i]<<"; ";
    }
    cout<<endl;
}