/*Q9. Write a C program that repeatedly reads words until EOF and 
classifies each word as: 
- a C keyword (from a small fixed list, e.g., int, if, else, for, while, return, char, float, double, void), 
- a valid identifier, - or an invalid token. 
Print the classification for each word.
*/

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
    unordered_set<string>kw={"int", "if", "else", "for", "while", "return", "char", "float", "double", "void"};
    string w;
    while(cin>>w)
    {
        if(kw.count(w)){cout<<w<<"  :Keyword\n";continue;}
        if(w.size()&&(isalpha(w[0])|| w[0]=='_'))
        {
            bool ok=true;
            for(size_t i=1;i<w.size();i++)
            {
                if(!(isalnum(w[i])||w[i]=='_')){ok=false;break;}
            }
            if(ok){ cout<<w<<"  :Identifire\n"<<'\n'; continue;}
        }
        cout<<w<<"  :Invalid\n"<<'\n';
    }

}
/*
 Q9: classify words until EOF: KEYWORD / IDENTIFIER / INVALID
#include <bits/stdc++.h>
using namespace std;
bool isIdStart(char c){ return isalpha((unsigned char)c) || c=='_'; }
bool isIdChar(char c){ return isalnum((unsigned char)c) || c=='_'; }
int main(){
    unordered_set<string> kw = {"int","if","else","for","while","return","char","float","double","void"};
    string w;
    while(cin >> w){
        if(kw.count(w)){ cout<<w<<" : KEYWORD\n"; continue; }
        if(w.size() && isIdStart(w[0])){
            bool ok=true;
            for(size_t i=1;i<w.size();++i) if(!isIdChar(w[i])){ ok=false; break; }
            if(ok){ cout<<w<<" : IDENTIFIER\n"; continue; }
        }
        cout<<w<<" : INVALID\n";
    }
}
*/

/* 
input-output:
int  :Keyword
sum  :Identifire

a1  :Identifire

2ab  :Invalid

for  :Keyword
hello!  :Invalid

abc_123  :Identifire

float  :Keyword
_abc  :Identifire

x-y  :Invalid

return  :Keyword
*/


