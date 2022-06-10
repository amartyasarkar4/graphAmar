#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
    // vector<char>fullS;
    string full="";
    int pos=0;
    vector<long int>myRepeatS(26,0);
    
    vector<long int>mysS(26,0);
    for(long int j=0;j<s.size();j++){
        cout<<"f:"<<s[j]<<endl;
        mysS[s[j]-'a']++;
    }
    int total=0;
    for(long int i=0;i<n;i+=s.size()){
        
        if(total+s.size()<=n){
            full+=s;
            total+=s.size();
            for(int i=0;i<26;i++){
                myRepeatS[i]+=mysS[i];
            }
        }else{
            for(int i=0;i<(n-total);i++){
                full.push_back(s[i]);
                total++;
                myRepeatS[full[i]-'a']++;
            }
            
        }
        // if(pos>s.size()-1)pos=0;
        // cout<<"s[pos]:"<<s[pos]<<":"<<pos<<endl;
        // fullS.push_back(s[pos]);
        // pos++;
    }
    // vector<long int>myRepeatS(26,0);
    // for(long int j=0;j<n;j++){
    //     cout<<"f:"<<full[j]<<endl;
    //     myRepeatS[full[j]-'a']++;
    // }
    long int maxi=INT_MIN;
    for(auto it:myRepeatS){
        if(it>maxi){
            maxi=it;        }
    }
    cout<<maxi<<endl;
    return maxi;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
