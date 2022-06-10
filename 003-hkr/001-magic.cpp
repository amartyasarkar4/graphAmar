#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>alltotals(vector<vector<int>> s){
    cout<<"\nBefore perform op:"<<endl;
    for(auto it:s){
        for(auto ic:it){
            cout<<ic<<" ";
        }
        cout<<endl;
    }
    vector<int>rowtoatal;
    vector<int>columntoal;
    vector<int>diagonaltotal;
    
    vector<int>columns(s[0].size(),0);
    int leftDiagonal=0;
    int rightDiagonal=0;
    vector<int>finalarr;
    for(int i=0;i<s.size();i++){
        int sngRowtotal=0;
        for(int j=0;j<s[i].size();j++){
            sngRowtotal+=s[i][j];
            columns[j]+=s[i][j];
            if(i==j)leftDiagonal+=s[i][j];
            if(j==s[i].size()-i-1)rightDiagonal+=s[i][j];
        }
        rowtoatal.push_back(sngRowtotal);
    }
    diagonaltotal.push_back(leftDiagonal);
    diagonaltotal.push_back(rightDiagonal);
    for(auto it:rowtoatal){
        finalarr.push_back(it);
    }
    for(auto it:columns){
        finalarr.push_back(it);
    }
    for(auto it:diagonaltotal){
        finalarr.push_back(it);
    }
    int total=0;
    for(auto it:finalarr){
        total+=it;
        cout<<it<<"==";
    }
    cout<<"total: "<<total<<endl;
    vector<vector<int>>myall;
    myall.push_back(rowtoatal);
    myall.push_back(columns);
    myall.push_back(diagonaltotal);
    return myall;
}
int formingMagicSquare(vector<vector<int>> s) {
    int cost=0;
    if(s[1][1]!=5){
        if(s[1][1]>5){
            int prev=s[1][1];
            s[1][1]-=s[1][1]-5;
            cost+=abs(prev-s[1][1]);
        }else{
            int prev=s[1][1];
            s[1][1]+=5-s[1][1];
            cost+=abs(s[1][1]-prev);
        }
    }
    vector<vector<int>>Tot=alltotals(s);
    for(auto it:Tot){
        for(auto ia:it){
            cout<<ia<<"==";
        }
        cout<<endl;
    }
    vector<int>newrow=Tot[0];
    vector<int>newcol=Tot[1];
    vector<int>newdia=Tot[2];
    
    
    for(int i=0;i<newrow.size();i++){
        if(newrow[i]!=15){
            for(int j=0;j<newcol.size();j++){
                cout<<"{"<<i<<":"<<j<<"}"<<endl;
                cout<<"newCol[j]:"<<newcol[j]<<endl;
                if(i==1&&j==1){
                    cout<<"oh:"<<i<<j<<endl;
                    continue;
                }
                else if(newcol[j]!=15){
                    cout<<"ohoo:"<<i<<j<<endl;
                    if(newcol[j]>15){
                        int prev=s[i][j];
                        if(i==0 && j==0 && newdia[0]==15){
                            cout<<"jjjjjjjjjjj"<<endl;
                            continue;
                        }
                        s[i][j]-=newcol[j]-15;
                        newcol[j]=15;
                        cost+=abs(prev-s[i][j]);
                    }else{
                        if(i==0 && j==0 && newdia[0]==15){
                            cout<<"jjjjjjjjjjj"<<endl;
                            continue;
                        }
                        if(newrow[i]>15){
                            int prev=s[i][j];
                            s[i][j]-=newrow[i]-15;
                            newrow[i]=15;
                            newcol[j]=newcol[j]-prev+s[i][j];
                            cost+=abs(prev-s[i][j]);
                            continue;
                        }
                        
                        int prev=s[i][j];
                        s[i][j]+=15-newcol[j];
                        newcol[j]=15;
                        cost+=abs(prev-s[i][j]);
                    }
                    break;
                }
                cout<<"lastme"<<endl;
                // break;
                
            }
        }
    }
    vector<vector<int>>Tot2=alltotals(s);
    for(auto it:Tot2){
        for(auto ib:it){
            cout<<ib<<"==";
        }
        cout<<endl;
    }
    cout<<"\nafter perform op:"<<endl;
    for(auto it:s){
        for(auto ic:it){
            cout<<ic<<" ";
        }
        cout<<endl;
    }
    cout<<"cost:"<<cost<<endl;
    return cost;
}
string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }
    formingMagicSquare(s);
    // int result = formingMagicSquare(s);

    // fout << result << "\n";

    fout.close();

    return 0;
}

