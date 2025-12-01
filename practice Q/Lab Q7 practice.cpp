/*Q7. An NFA has two states: q0 (start) and q1 (accept). 
Transitions: - From q0 on input a → q1 - From q1 on input b or c → q1 
This NFA accepts strings of the form a(b|c)*. 
Write a C program that simulates this NFA (by tracking the set of current states) and 
prints whether a given input string is accepted.
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
    if(!getline(cin,s))return 0;//empty
    s.erase(remove_if(s.begin(),s.end(),::isspace),s.end()); // remove all whitespace
    
    bool cur0=true,cur1=false;  
    for(char c:s)
    {
        bool q0=false,q1=false;
        if(cur0 &&c=='a')q1=true;  // q0 --a--> q1
        if(cur1 && (c=='b' || c=='c'))q1=true;  // q1 --b/c--> q1
        cur0=q0,cur1=q1;
        if( !cur0 && !cur1){cout<<"Rejected\n";return 0;}
    }
    cout<<(cur1 ? "Accepted\n" : "Rejected\n");
}
/* NFA concept for a(b|c)*
q0 → start
q1 → accept

accepted:
a       Starts with a, no further symbols → accepted
ab      a → q1, b → q1 → accepted
ac      a → q1, c → q1 → accepted
abbc    a → q1, b → q1, b → q1, c → q1 → accepted
accc    a → q1, c → q1, c → q1, c → q1 → accepted
abcbcb  a → q1, b → q1, c → q1, b → q1, c → q1, b → q1 → accepted

rejected:
b       Starts with b, cannot move from q0 → rejected
c       Starts with c, cannot move from q0 → rejected
aa      a → q1, then a → no transition from q1 → rejected
abcab   After first a → q1, b → q1, c → q1, a → no transition from q1 → rejected
(empty string)   Starts in q0, no input, q0 is not accepting → rejected
*/