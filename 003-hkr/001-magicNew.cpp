#include<bits/stdc++.h>
using namespace std;
class CalTotalOfRowColDia{
    public:
    vector<int>rowtotal;
    vector<int>columnTotal;
    vector<int>diagonaltotal;
    
    void alltotals(vector<vector<int>> s){
        vector<int>columns(s[0].size(),0);
        int leftDiagonal=0;
        int rightDiagonal=0;
        for(int i=0;i<s.size();i++){
            int sngRowtotal=0;
            for(int j=0;j<s[i].size();j++){
                sngRowtotal+=s[i][j];
                columns[j]+=s[i][j];
                if(i==j)leftDiagonal+=s[i][j];
                if(j==s[i].size()-i-1)rightDiagonal+=s[i][j];
            }
            rowtotal.push_back(sngRowtotal);
        }
        diagonaltotal.push_back(leftDiagonal);
        diagonaltotal.push_back(rightDiagonal);
        for(int i=0;i<columns.size();i++){
            columnTotal.push_back(columns[i]);
        }
    }
    void updatetotals(vector<vector<int>> s){
        vector<int>columns(s[0].size(),0);
        int leftDiagonal=0;
        int rightDiagonal=0;
        for(int i=0;i<s.size();i++){
            int sngRowtotal=0;
            for(int j=0;j<s[i].size();j++){
                sngRowtotal+=s[i][j];
                columns[j]+=s[i][j];
                if(i==j)leftDiagonal+=s[i][j];
                if(j==s[i].size()-i-1)rightDiagonal+=s[i][j];
            }
            rowtotal[i]=(sngRowtotal);
        }
        diagonaltotal[0]=(leftDiagonal);
        diagonaltotal[1]=(rightDiagonal);
        for(int i=0;i<columns.size();i++){
            columnTotal[i]=columns[i];
        }
    }
};


void formingMagicSquare(vector<vector<int>> s) {
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
    CalTotalOfRowColDia c1;
    c1.alltotals(s);    
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s[i].size();j++){
            cout<<"{"<<i<<":"<<j<<"}"<<endl;
            if(i==1&&j==1){
                cout<<"oh:"<<i<<j<<endl;
                continue;
            }
            else{
                if(c1.rowtotal[i]!=15){
                    if(i==0 && j==0 && c1.diagonaltotal[0]==15){
                        continue;
                    }
                    else if(c1.rowtotal[i]>15){
                        if(c1.columnTotal[j]>15){
                            int prv=s[i][j];
                            s[i][j]-=(c1.columnTotal[j]-15);
                            cost+=abs(prv-s[i][j]);
                            c1.updatetotals(s);
                            
                        }else{
                            int prv=s[i][j];
                            s[i][j]-=(c1.rowtotal[i]-15);
                            cost+=abs(prv-s[i][j]);
                            c1.updatetotals(s);
                            
                        }
                    }else{
                        if(c1.columnTotal[j]!=15){
                            if(i==0&& j==0 &&c1.diagonaltotal[0]==15){
                                continue;
                            }
                            if(c1.columnTotal[j]>15){
                                int prv=s[i][j];
                                s[i][j]-=(c1.columnTotal[j]-15);
                                cost+=abs(prv-s[i][j]);
                                c1.updatetotals(s);
                                
                            }else{
                                int prv=s[i][j];
                                cout<<prv<<"prv"<<endl;

                                s[i][j]+=(15-c1.columnTotal[j]);
                                cout<<s[i][j]<<"aft"<<endl;
                                cost+=abs(s[i][j]-prv);
                                c1.updatetotals(s);
                                
                            }
                        }
                    }
                }
            }
        }
           
    }
    
    cout<<"\nafter perform op:"<<endl;
    for(auto it:s){
        for(auto ic:it){
            cout<<ic<<" ";
        }
        cout<<endl;
    }

    for(auto it:c1.rowtotal){
        cout<<it<<"==";
    }
    cout<<endl;
    for(auto it:c1.columnTotal){
        cout<<it<<"==";
    }
    cout<<endl;
    for(auto it:c1.diagonaltotal){
        cout<<it<<"==";
    }
    cout<<"cost:"<<cost<<endl;
    // return cost;
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
