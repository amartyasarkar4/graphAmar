#include<bits/stdc++.h>
using namespace std;


vector<int> climbingLeaderboard(vector<int> &ranked, vector<int> &player) {
    vector<int>leaderRank;
    set<int,greater<int>>runs;
    for(auto &it:ranked){
        runs.insert(it);
    }
    vector<int> v(runs.begin(), runs.end());
    for(long int i=0;i<player.size();i++){
        long int nowRank=1;
        // set<int>::iterator it;
        // for(it=runs.begin();it!=runs.end();){
        //     int mpoint=runs.size()/2;
        //     if(player[i]>*it){
        //         break;
        //     }else{
        //         nowRank++;
        //     }
        // }
        nowRank =lower_bound(v.begin(), v.end(), player[i],greater<int>())-v.begin();
        leaderRank.push_back(nowRank+1);
    }
    return leaderRank;
}
// vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
//     vector<int>leaderRank;
//     set<int,greater<int>>runs;
//     for(auto it:ranked){
//         runs.emplace(it);
//     }
//     for(auto i:runs){
//         cout<<i<<endl;
//     }
//     // vector<int> v(runs.begin(), runs.end());
//     // int k=runs.begin();
//     // cout<<"jj:"<<k<<endl;
//     // for(auto i:v){
//     //     cout<<i<<endl;
//     // }
    
//     for(int i=0;i<player.size();i++){
//         int nowRank=1;
//         set<int>::iterator it;
//         for(it=runs.begin();it!=runs.end();it++){
//             if(player[i]>=*it){
//                 break;
//             }else{
//                 nowRank++;
//             }
//         }
        
//         leaderRank.push_back(nowRank);
//     }
//     return leaderRank;
// }

int main(){
    vector<int>ranked={100,100,50,40,40,20,10};
    vector<int>player={5,25,50,120};
    vector<int>listarnk=climbingLeaderboard(ranked,player);
    for(auto it:listarnk){
        cout<<it<<"==";
    }
}