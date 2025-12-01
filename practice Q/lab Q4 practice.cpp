
/* Q4. The grammar S → a S b | a b generates strings of the form a^n b^n.
 Write a recursive-descent C program that reads a string over {a, b} and
  checks whether it belongs to this language.
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

bool S()
{
    if(ind<s.size()&&s[ind]=='a')
    {
        ind++;
        if(ind<s.size()&&s[ind]=='b'){ind++;return true;}// base "ab"
        if(!S())return false;     //S ->a S b
        
        if(ind>=s.size() || s[ind]!='b')return false;
        ind++;
        return true;
    }
    return false;  //empty
}


int32_t main()
{
    fast;
    getline(cin,s);
    s.erase(remove(s.begin(),s.end(),' '),s.end()); // remove space
    ind=0;
    ll ans=S() && ind==s.size();
    cout<<(ans ? "Accepted\n" : "Rejected\n");
}
/* 
aⁿ bⁿ     (n ≥ 1)

valid input:

ab
aabb
aaabbb
aaaabbbb
invalid input:
abab
aab
abb
baa
aabb b

*/

