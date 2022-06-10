#include <bits/stdc++.h>
#include <string.h>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string timeR;
    string BF=s.substr(8,2);
    cout<<BF<<endl;
    string OnlyTime=s.substr(0,8);
    if(BF=="PM"){
        // cout<<"hh";
        string hourS=OnlyTime.substr(0,2);
        stringstream ss;
        ss<<hourS;
        int hour=0;
        ss>>hour;
        if(hour>=12){
            hour-=12;
        }
        hour+=12;
        ostringstream mstr;
        mstr<<hour;
        string last = mstr.str();
        
        string fulltime=last+OnlyTime.substr(2);
        return fulltime;
    }else{
        string hourS2=OnlyTime.substr(0,2);
        stringstream ss2;
        ss2<<hourS2;
        int hour2=0;
        ss2>>hour2;
        string last2;
        if(hour2>=12){
            // hour2-=12;
            // ostringstream mstr2;
            // mstr2<<hour2;
            last2 = "00";
        }else{
            last2=hourS2;
        }
        
        
        string fulltime2=last2+OnlyTime.substr(2);
        return fulltime2;
    }
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";

    // fout.close();

    return 0;
}
