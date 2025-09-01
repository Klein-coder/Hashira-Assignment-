#include <bits/stdc++.h>
using namespace std;

long long conv(string s,int b){
    long long x=0;
    for(char c:s){
        int d;
        if(isdigit(c)) d=c-'0';
        else d=10+(tolower(c)-'a');
        x=x*b+d;
    }
    return x;
}

vector<long long> makePoly(vector<long long> rr){
    vector<long long> aa={1,-rr[0]};
    for(int i=1;i<rr.size();i++){
        vector<long long> tt(aa.size()+1);
        for(int j=0;j<aa.size();j++) tt[j]+=aa[j];
        for(int j=0;j<aa.size();j++) tt[j+1]+=-rr[i]*aa[j];
        aa=tt;
    }
    return aa;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string inp((istreambuf_iterator<char>(cin)),istreambuf_iterator<char>());
    int nn=0,kk=0;
    vector<long long> rr;
    size_t p=inp.find("\"n\"");
    if(p!=string::npos){p=inp.find(":",p);nn=stoi(inp.substr(p+1));}
    p=inp.find("\"k\"");
    if(p!=string::npos){p=inp.find(":",p);kk=stoi(inp.substr(p+1));}
    size_t q=0;
    while(1){
        size_t b=inp.find("\"base\"",q);
        if(b==string::npos) break;
        size_t c=inp.find(":",b);
        size_t d=inp.find(",",c);
        string bs;
        for(size_t i=c+1;i<d;i++) if(isalnum(inp[i])) bs.push_back(inp[i]);
        int bb=stoi(bs);
        size_t v=inp.find("\"value\"",d);
        c=inp.find(":",v);
        size_t q1=inp.find("\"",c+1);
        size_t q2=inp.find("\"",q1+1);
        string val=inp.substr(q1+1,q2-q1-1);
        rr.push_back(conv(val,bb));
        q=q2;
    }
    sort(rr.begin(),rr.end());
    rr.resize(kk-1);
    vector<long long> aa=makePoly(rr);
    for(int i=0;i<aa.size();i++){
        cout<<aa[i]<<(i+1==aa.size()?"\n":" ");
    }
}