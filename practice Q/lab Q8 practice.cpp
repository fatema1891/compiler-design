/*Q8. Write a simple lexical analyzer in C that 
reads a single line of input and splits it into tokens of three types: 
- IDENTIFIER (starting with a letter or _, followed by letters/digits/_) 
- NUMBER (sequence of digits) 
- SYMBOL (any other single character) 
For each token, print its type and lexeme.
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

    /*s.erase(remove(s.begin(),s.end(),' '),s.end()); // remove space

    error for p = a1 + 123 34; because two number 123 and 34.
     but using this function given one number 12334
    */
    
    ll n=s.size(),i,j;
    for( i=0;i<n;)
    {
        if(isspace(s[i])){i++;continue;}
        if(isalpha(s[i]) || s[i]=='_')
        {
             j=i;
            while(j<n &&(isalnum(s[j])||s[j]=='_'))j++;

            cout<<"Identifire \t"<<s.substr(i,j-i)<<'\n';
            i=j;
        }
        else if(isdigit(s[i]))
        {
            j=i;
            while(j<n&&isdigit(s[j]))j++;

            cout<<"Number\t\t"<<s.substr(i,j-i)<<'\n';
            i=j;
        }
        else
        {
            cout<<"Symbol\t\t"<<s[i]<<'\n';
            i++;
        }
    }
   
}
/*input:
  sum = a1 + 123 234;

  output:
Identifire    sum
Symbol      =
Identifire  a1
Symbol      +
Number      123
Number      234
Symbol      ;

*/