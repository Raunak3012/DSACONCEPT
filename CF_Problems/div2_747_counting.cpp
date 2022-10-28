// think well and correct, code well and correct...
// if one approach is stuck try to think of other approaches, 
// observe patterns through examples etc.
// and duirng a contest/interview, 
// try doing the above  as fast as possible

#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
using namespace std;

#include <limits>

typedef std::numeric_limits< double > dbl;

typedef long long ll;
typedef unsigned long long ull;

#define pf push_front
#define pb push_back


ll gcd(ll a, ll b){
  if (b == 0){ return a; }
  return gcd(b, a % b);
}

ll mod = 998244353; //REMEMBER HANDLING OF NEGATIVE MODULO

ll MOD = (1e9)+7;


ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y)
{
  // binary exponentiation https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/
    ll z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

ll inv(ll x)
{   // Fermat's little theorem
    return binpow(x, MOD - 2);
}

ll divide(ll x, ll y)
{
    return mul(x, inv(y));
}


////////////////////////////////////////////////////////////////////////////////

//const int MX = 1 + (int)pow(10,2);
// BE careful with size_t, its for unsigned only
//READ THE QUESTION CORRECTLY AND CAREFULLY (EDU DIV2 101)



//std::vector<int> primes;

//std::vector<int> sieve(10000001,1);

//const int N = 1050;
//const int V = 1100;
//int C[V][V];
//#include <stdio.h>

int cnt_prime(int a){
  int cn1 = 0;
  int n1_t = a;
  for(int i=2;i*i<=a;i++){
    while(n1_t%i==0){
      n1_t/=i;
      cn1++;
    }
  }
  if(n1_t!=1){
    cn1++;
  }

  return cn1;
}



ll pw(int k){
  ll re = 1;
  while (k--) {
    re*=2;
  }
  return re;
}

// vector<int> dp;

ll mybinpow(ll b, ll e){

  if(e==0){
    return 1;
  }

  if(e%2==0){
    ll temp =   mybinpow(b ,e/2)%MOD;
    return (temp*temp)%MOD;
  
  }
  else{
    ll temp =   mybinpow(b ,e/2)%MOD;
    return ((temp*temp)%MOD *(b%MOD))%MOD;
  }

}

int dlp(int x){
  int ans = 0;
  while(x>0){
    ans++;
    x/=10;    
  }
  return ans;
}



int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    #endif

    ios::sync_with_stdio(0);cin.tie(0);

    cout.precision(dbl::max_digits10);

    
    /*
    //std::vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        //sieve[i]+=i;
        //primes.pb(i);
        for(int j=2*i;j<=(n);j+=i){
          sieve[j]+=1;
        }
    }
    
  
    //std::cout << primes.size() << '\n';
    /*
    for(int i=0;i<=N;i++){
      C[i][0] = 1;C[i][i]=1;
      for(int j=1;j<i;j++){
        C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
      }
    }
*/
    ll k;
    cin>>k;

    ll nums = ((ll)1 << k) - 1;

    cout<< (6*binpow((ll)4, nums-1))%MOD<<"\n";

   
    


    
    return 0;
}
