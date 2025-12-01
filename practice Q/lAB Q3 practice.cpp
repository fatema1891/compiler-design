
/* QQ3. Using the grammar S → ( S ) S | ε,
 write a recursive-descent C program that reads a string of parentheses (only ( and )) and
  prints whether it is a valid balanced string according to this grammar.
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
    if(ind<s.size() &&s[ind]=='(')
    {
        ind++;
        if(!S())return false;
        if(ind>=s.size() || s[ind]!=')')return false;
        ind++;
        if(!S())return false;
        return true;
    }
    return true;  // epsilon (empty input)
}

int32_t main()
{
    fast;
    getline(cin,s);
    s.erase(remove(s.begin(),s.end(),' '),s.end()); // remove space
    ind=0;
    ll ans=S() && ind==s.size();
    cout<<(ans ? "valid balance\n" : "invalid balance\n");
}
/* valid input:
()
(())()
(()(()))
invalid input:
(
)
(()))
(()()
*/

