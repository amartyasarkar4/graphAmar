vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<int>dynamicArr;
    long int lastAnswer=0;
    const int N=1e5;
    vector<long int>arr[N];
    
    for(long int i=0;i<queries.size();i++){
        long int x=queries[i][1];
        long int y=queries[i][2];
        
        if(queries[i][0]==1){
            int idx=(x^lastAnswer)%n;
            cout<<idx<<endl;
            arr[idx].push_back(y);
        }else if(queries[i][0]==2){
            long int idx=(x^lastAnswer)%n;
            int actPos=y%arr[idx].size();
            lastAnswer=arr[idx][actPos];
            dynamicArr.push_back(lastAnswer);
        }
    }
    return dynamicArr;
}
