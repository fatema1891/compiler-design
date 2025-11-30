
/* Q1. Using the grammar L → id | id , L
 where id is an identifier starting with a letter or _ followed by letters, digits, or _, 
write a C program using recursive descent to check whether a given comma-separated list (e.g., a, a,b,c, x1, y2) is valid.
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

//isalpha(c) ;Returns true if the char c is an alphabet letter: A-Z or a-z
bool identifire_start(char c)
{
    //if(isalpha((unsigned char)c)  || c=='_')return true;
      return isalpha((unsigned char)c) || c=='_';
    //else false;
}

//isalnum(c) ;Returns true if the char c is alphanumeric: A–Z, a–z ,0–9
bool indentifire_char(char c)
{
    return isalnum((unsigned char)c)  || c=='_';
}

bool parse_id()
{
    if(ind>=s.size() || ! identifire_start(s[ind]))return false;
    ind++;
    while(ind<s.size()&&indentifire_char(s[ind])) ind++;
    return true;
}

bool parse_L()
{
    if(!parse_id())return false; //Parse_id means parse an identifier; L-> id
   
    if(ind<s.size()&&s[ind]==',')   // L ->  , L
    {
        ind++;
        return parse_L();// true or false
    }
    return true;
}
 
 int32_t main()
 {
    fast;

    getline(cin,s);
    ind=0;
    s.erase(remove(s.begin(),s.end(),' '),s.end());
    bool ans=parse_L();  // L->id(identifire) | id (indentifire) , L
    cout << ((ans==true && ind==s.size())  ? "valid\n" : "Invalid\n");

 }
 /* Valid:
 a.
a,b,c
x1,y2
_abc,_d2
a1,_b2,c3

invalid:
1a
a,,b
a,
,a
a,b,
*/
 