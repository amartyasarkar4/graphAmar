#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
    int pickedno=0;
    vector<int>taken(100,0);
    for(int i=0;i<a.size();i++){
        taken[a[i]]++;
    }
    for(int i=0;i<=100;i++){
        int count=taken[i]+taken[i+1];
        if(count>pickedno){
            pickedno=count;
        }
    }
    return pickedno;
}

int main()
{
    int n;
    cin>>n;
    vector<int>a={};
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    int no=pickingNumbers(a);
    cout<<no<<endl;
    
    

    return 0;
}

