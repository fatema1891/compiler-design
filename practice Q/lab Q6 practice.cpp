/*Q6. Write a C program to simulate a DFA that 
accepts all binary strings that contain an even number of 1s. 
Use a small transition table (2 states × 2 symbols) and 
print “Accepted” or “Rejected” for the input string.
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
    
    ll state=0;  //2 state means even or odd and 2 symbol 0 or 1
    for(char c:s)
    {
        //if(c!='0'&&c!='1'){cout<<"Rejected";return 0;}//binary string
        if(c=='1')state^=1;
    }
    cout<<(state==0 ? "Accepted\n" : "Rejected\n");
}

