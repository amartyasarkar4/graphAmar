long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<int>myArr(n+1,0);
    long int Highest=INT_MIN;
    for(long int i=0;i<queries.size();i++){
        for(long int j=queries[i][0];j<=queries[i][1];j++){
            myArr[j]+=queries[i][2];
            if(myArr[j]>Highest){
                Highest=myArr[j];
            }
        }
    }
    
    return Highest;
    // long int Highest=INT_MIN;
    for(long int i=0;i<=n;i++){
        // cout<<myArr[i]<<endl;
        if(myArr[i]>Highest){
            Highest=myArr[i];
        }
    }
}
