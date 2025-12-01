
/* Q5. Design and implement in C a DFA simulator that 
accepts all binary strings (over 0 and 1) that end with the substring 01.
The program should read one input string and
 print “Accepted” if it ends with 01, otherwise “Rejected”.
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
    
    ll state=0;
    for(char c:s)
    {
        if(state==0&&c=='0')state=1;
        else if(state==1&&c=='1')state=2;
        else if(state==2)
        {
            if(c=='0')state=1;
            else state=0;
        }
    }
    cout<<(state==2 ? "Accepted\n" : "Rejected\n");
}
/* 

valid input:    end with "01"
01
101
0001
1101
1001
invalid input:
10
1010
010
0011
0
1

*/

