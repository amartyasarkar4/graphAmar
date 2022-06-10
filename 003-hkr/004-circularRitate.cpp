#include <bits/stdc++.h>

using namespace std;

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int>Ans;
    queue<int>circular;
    vector<int>finalArr(a.size(),0);
    for(int i=a.size()-1;i>=0;i--){
        circular.push(a[i]);
    }
    for(int j=0;j<k;j++){
        int firstWillbelast=circular.front();
        circular.pop();
        circular.push(firstWillbelast);
    }
    for(int m=circular.size()-1;m>=0;m--){
        finalArr[m]=circular.front();
        circular.pop();
    }
    // for(auto f:finalArr){
    //     cout<<f<<"=";
    // }
    for(int l=0;l<queries.size();l++){
        int pos=queries[l];
        Ans.push_back(finalArr[queries[l]]);
    }
    return Ans;
}

int main(){
    vector<int>a;
    vector<int>query;
    int n,k,q;
    cin>>n;
    cin>>k;
    cin>>q;
    for(int i=0;i<n;i++){
        int el;
        cin>>el;
        a.push_back(el);
    }
    for(int j=0;j<q;j++){
        int ee;
        cin>>ee;
        query.push_back(ee);
    }
    vector<int>ans=circularArrayRotation(a,k,query);
    for(auto it:ans){
        cout<<it<<"=";
    }

}