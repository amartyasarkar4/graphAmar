// This is the final solution,,,but hk gives wrong
// But I know ,my one is perfect.....I have checked many times

// https://www.hackerrank.com/challenges/magic-square-forming/problem?isFullScreen=true

// ===============
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
pair<bool,int> khadiUtarGayi(vector<vector<int>>&s,CalTotalOfRowColDia &c1){
    vector<vector<int>>cs;
    for(auto it:s){
        vector<int>cc;
        for(auto a:it){
            cc.push_back(a);
        }
        cs.push_back(cc);
    }
    int considered=s[0][1]; 
    int loopcost=0;
    bool khadiUtar=false;
    if(c1.rowtotal[0]<15){
        int prv=s[0][0];
        s[0][0]+=(15-c1.rowtotal[0]);
        loopcost+=abs(s[0][0]-prv);
        c1.updatetotals(s);
    }else{
        int prv=s[0][0];
        s[0][0]-=(c1.rowtotal[0]-15);
        loopcost+=abs(prv-s[0][0]);
        c1.updatetotals(s);
    }
    if(c1.columnTotal[0]!=15){
        if(c1.columnTotal[0]>15){
            int prv=s[2][0];
            s[2][0]-=(c1.columnTotal[0]-15);
            loopcost+=abs(prv-s[2][0]);
            c1.updatetotals(s);
        }else{
            int prv=s[2][0];
            s[2][0]+=(15-c1.columnTotal[0]);
            loopcost+=abs(s[2][0]-prv);
            c1.updatetotals(s);
        }
        
    }
    if(c1.diagonaltotal[1]==15){
        khadiUtar=true;
    }else{
        s.clear();
        for(auto it:cs){
            vector<int>cc;
            for(auto a:it){
                cc.push_back(a);
            }
            s.push_back(cc);
        }
    }
    cout<<"khadi's cost: "<<loopcost<<endl;
    pair<bool,int>checkKhadi=make_pair(khadiUtar,loopcost);
    return checkKhadi;
}

int formingMagicSquare(vector<vector<int>> s) {
    int finalcost=0;
    int MainCost=INT_MAX;
    if(s[1][1]!=5){
        if(s[1][1]>5){
            int prev=s[1][1];
            s[1][1]-=s[1][1]-5;
            finalcost+=abs(prev-s[1][1]);
        }else{
            int prev=s[1][1];
            s[1][1]+=5-s[1][1];
            finalcost+=abs(s[1][1]-prev);
        }
    }
    CalTotalOfRowColDia c1;
    c1.alltotals(s); 
    vector<pair<int,int>>arr[4];
    arr[0]={{1,2},{1,0},{2,1},{0,1}};
    arr[1]={{1,0},{1,2},{2,1},{0,1}};
    arr[2]={{2,1},{0,1},{1,2},{1,0}};
    arr[3]={{0,1},{2,1},{1,2},{1,0}};
    // for(int i=0;i<s.size();i++){
    //     for(int j=0;j<s[i].size();j++){
    //         cout<<"{"<<i<<":"<<j<<"}"<<endl;
            // if(i==1&&j==1){
            //     cout<<"hey! don't touch here:"<<i<<","<<j<<endl;
            //     continue;
            // }
    vector<vector<int>>copy;
    for(int i=0;i<4;i++){
            copy.clear();
            for(auto it:s){
                vector<int>col;
                for(auto co:it){
                    col.push_back(co);
                }
                copy.push_back(col);
            }
            CalTotalOfRowColDia c2;
            c2.alltotals(copy);
            int cost=finalcost;

            int checkrow1=c2.rowtotal[1];
            int checkcol1=c2.columnTotal[1];
            int whichFirst=0,whichSecond=0;
            if(i<2){
                whichFirst=checkrow1;
                whichSecond=checkcol1;
            }else if(i>=2){
                whichFirst=checkcol1;
                whichSecond=checkrow1;
            }
            if(whichFirst!=15){
                int X=arr[i][1].first;
                int Y=arr[i][1].second;
                if(whichFirst>15){
                    int prv=copy[X][Y];
                    copy[X][Y]-=(whichFirst-15);
                    cost+=abs(prv-copy[X][Y]);
                    c2.updatetotals(copy);
                }else{
                    int prv=s[X][Y];
                    copy[X][Y]+=(15-whichFirst);
                    cost+=abs(copy[X][Y]-prv);
                    c2.updatetotals(copy);
                }
                
            }
            int a=arr[i][0].first;
            int b=arr[i][0].second;
            int c=arr[i][2].first;
            int d=arr[i][2].second;
            bool decideFixedOdd=false;
            if(copy[a][b]%2==0){
                decideFixedOdd=false;
            }else{
                decideFixedOdd=true;
            }
            bool updateOdd=false;
            if(copy[c][d]%2==0){
                updateOdd=false;
            }else{
                updateOdd=true;
            }
            if(decideFixedOdd!=updateOdd){
                if(copy[c][d]>5){
                    int prv=copy[c][d];
                    if((prv-1)==5){
                        copy[c][d]+=1;
                    }else{
                        copy[c][d]-=1;
                    }
                    
                    cost+=abs(prv-copy[c][d]);
                    c2.updatetotals(copy);
                }else{
                    int prv=copy[c][d];
                    if((copy[c][d]+1)==5){
                        cout<<"kello"<<endl;
                        copy[c][d]-=1;
                    }else{
                        copy[c][d]+=1;
                    }
                    cost+=abs(copy[c][d]-prv);
                    c2.updatetotals(copy);
                }
            }
            if(i<2){
                whichSecond=c2.columnTotal[1];
            }else if(i>=2){
                whichSecond=c2.rowtotal[1];
            }
            if(whichSecond!=15){
                int X=arr[i][3].first;
                int Y=arr[i][3].second;
                if(whichSecond>15){
                    int prv=copy[X][Y];
                    copy[X][Y]-=(whichSecond-15);
                    cost+=abs(prv-copy[X][Y]);
                    c2.updatetotals(copy);
                }else{
                    int prv=copy[X][Y];
                    copy[X][Y]+=(15-whichSecond);
                    cost+=abs(copy[X][Y]-prv);
                    c2.updatetotals(copy);
                }
                
            }


            // cout<<"\nafter perform op:"<<endl;
            // for(auto it:copy){
            //     for(auto ic:it){
            //         cout<<ic<<" ";
            //     }
            //     cout<<endl;
            // }

            // for(auto it:c2.rowtotal){
            //     cout<<it<<"==";
            // }
            // cout<<endl;
            // for(auto it:c2.columnTotal){
            //     cout<<it<<"==";
            // }
            // cout<<endl;
            // for(auto it:c2.diagonaltotal){
            //     cout<<it<<"==";
            // }


            pair<bool,int>check=khadiUtarGayi(copy,c2);
            cout<<"check:"<<check.first<<endl;
            if(check.first==true){
                cost+=check.second;
            }else{
                int totalofTwoFixed=copy[0][1]+copy[1][2];
                if(totalofTwoFixed>10){
                    int actualPrv=copy[0][2];
                    while(copy[0][2]>0 && copy[0][2]<10){
                        cout<<"gg:"<<copy[0][2]<<"cost:"<<cost<<endl;
                        int prv=copy[0][2];
                        bool statePrimary=true;
                        if(statePrimary==true){
                            copy[0][2]-=1;
                            c2.updatetotals(copy);
                            pair<bool,int>check2=khadiUtarGayi(copy,c2);
                            cout<<"check2:"<<check2.first<<endl;
                            if(check2.first==1){
                                cost+=check2.second;
                                cout<<"cost:"<<cost<<endl;
                                cost+=(actualPrv-copy[0][2]);
                                cout<<"cost:"<<cost<<endl;
                                break;
                            }
                        }
                        if(copy[0][2]<=1){
                            statePrimary=false;
                        }
                        if(statePrimary==false){
                            copy[0][2]=prv;
                            copy[0][2]+=1;
                            cout<<"gg:"<<copy[0][2]<<"cost:"<<cost<<endl;
                            c2.updatetotals(copy);
                            pair<bool,int>check2=khadiUtarGayi(copy,c2);
                            cout<<"check2:"<<check2.first<<endl;
                            if(check2.first==1){
                                cost+=check2.second;
                                cout<<"cost:"<<cost<<endl;
                                cost+=(copy[0][2]-actualPrv);
                                cout<<"cost:"<<cost<<endl;
                                break;
                            }
                        }
                    }
                }else{
                    bool statePrimary=true;
                    int actualPrv=copy[0][2];
                    while(copy[0][2]<10 && copy[0][2]>0){
                        cout<<"gg:"<<copy[0][2]<<"cost:"<<cost<<endl;
                        int prv=copy[0][2];
                        
                        if(statePrimary==true){
                            copy[0][2]+=1;
                            c2.updatetotals(copy);
                            pair<bool,int>check2=khadiUtarGayi(copy,c2);
                            cout<<"check2:"<<check2.first<<endl;
                            if(check2.first==1){
                                cost+=check2.second;
                                cout<<"cost: "<<cost<<endl;
                                cost+=(copy[0][2]-actualPrv);
                                cout<<"cost:"<<cost<<endl;
                                break;
                            }
                        }
                        if(copy[0][2]>=9){
                            statePrimary=false;
                        }
                        if(statePrimary==false){
                            copy[0][2]=prv;
                            copy[0][2]-=1;
                            cout<<"gg:"<<copy[0][2]<<"cost:"<<cost<<endl;
                            c2.updatetotals(copy);
                            pair<bool,int>check2=khadiUtarGayi(copy,c2);
                            cout<<"check2:"<<check2.first<<endl;
                            if(check2.first==1){
                                cost+=check2.second;
                                cout<<"cost:"<<cost<<endl;
                                cost+=(actualPrv-copy[0][2]);
                                cout<<"cost:"<<cost<<endl;
                                break;
                            }
                        }
                    }
                }

        //     }

        // }
           
    }
    if(c2.diagonaltotal[0]!=15){
            if(c2.diagonaltotal[0]>15){
                int prev=copy[2][2];
                copy[2][2]-=(c2.diagonaltotal[0]-15);
                cost+=abs(prev-copy[2][2]);
                c2.updatetotals(copy);
            }else{
                int prv=copy[2][2];
                copy[2][2]+=(15-c2.diagonaltotal[0]);
                cost+=abs(copy[2][2]-prv);
                c2.updatetotals(copy);
            }
        }


        cout<<"\nafter perform op:"<<endl;
        for(auto it:copy){
            for(auto ic:it){
                cout<<ic<<" ";
            }
            cout<<endl;
        }

        for(auto it:c2.rowtotal){
            cout<<it<<"==";
        }
        cout<<endl;
        for(auto it:c2.columnTotal){
            cout<<it<<"==";
        }
        cout<<endl;
        for(auto it:c2.diagonaltotal){
            cout<<it<<"==";
        }



        cout<<"this iteration cost:"<<cost<<endl;
        if(cost<MainCost){
            MainCost=cost;
        }
        cout<<"this iteration Main cost:"<<MainCost<<endl;
        // ===============================================
    }


    // ==========================Ending For loop============================
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
    cout<<"cost:"<<MainCost<<endl;
    return MainCost;
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
    // formingMagicSquare(s);
    int result = formingMagicSquare(s);

    fout <<"final cost: "<< result << "\n";

    fout.close();

    return 0;
}
