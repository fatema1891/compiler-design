//Q10. Write a C program that reads C source code from standard input and outputs the same code but with all comments removed.
// Your program should remove: - single-line comments starting with // until the end of the line, and 
//- multi-line comments enclosed by /* and */.


#include<bits/stdc++.h>
using namespace std;
using ll= long long int;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using vl=std::vector<ll>;
using vll=vector<vl>;
using vb=vector<bool>;
const ll mod=1e9+7;

string s; ll ind;

int32_t main()
{
    fast;
    string src,s;
    while(getline(cin,s))
    {
        src+=s+"\n";
    }
    ll n=src.size();
    string result="";
    ll i;
    bool sngle=false,multiple=false;
    for(i=0;i<n;i++)
    {
        if(src[i]=='/'&&src[i+1]=='/'&&i+1<n)
            {sngle=true;i++;continue;}
        if(src[i]=='/'&&i+1<n&&src[i+1]=='*')
        {
            multiple=true;i++;continue;
        }
        if(sngle)
        {
            if(src[i]=='\n')
            {
                sngle=false;
                result+='\n';
                
            }
            continue;
        }
        if(multiple)
        {
            if(src[i]=='*'&&i+1<n&&src[i+1]=='/')
            {
                multiple=false;
                i++;

            }
            continue;
        }
        result+=src[i];
    }
    cout<<"output string without comment :\n"<<result<<'\n';
}

/*
input:
int a = 10; // initialize a
int b = 20;
/* comment
   spanning
   multiple lines */
// int c = a + b;                  //ai line ar comment ta input na

/* output:
output string without comment :
int a = 10; 
int b = 20;

int c = a + b;


*/

