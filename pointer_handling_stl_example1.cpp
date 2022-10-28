//***FIGHT THE BEST FOR THE PURPOSE FIGHT THE BEST BY THE LAWS***//
#include <bits/stdc++.h>
#include <limits>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef std::numeric_limits< double > dbl;

#define pf push_front
#define pb push_back

ll gcd(ll a, ll b){
  if (b == 0){ return a; }
  return gcd(b, a % b);
}
///////////////////////////////////////////////////////////////////////////////

int isP(int n){
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}
//std::vector<int> nos;
ll ps;

// with the help of editorial

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //cout.precision(dbl::max_digits10);

    ll t;
    std::cin >> t;
    while (t--) {
      ll nr, ng,nb;
      std::cin >> nr>>ng>>nb;
      std::vector<ll> r(nr),g(ng),b(nb);

      for (int i = 0; i < nr; i++) {
        /* code */
        std::cin >> r[i];
      }
      for (int i = 0; i < ng; i++) {
        /* code */
        std::cin >> g[i];
      }
      for (int i = 0; i < nb; i++) {
        /* code */
        std::cin >> b[i];
      }
      sort(r.begin(),r.end());
      sort(g.begin(),g.end());
      sort(b.begin(),b.end());

      std::vector<ll> v;

      for (int i = 0; i <nr; i++) {
        ll rr = r[i];

        auto it1 = lower_bound(g.begin(),g.end(),rr);
        auto it2 = lower_bound(b.begin(),b.end(),rr );

        auto it1l = it1-1;
        auto it2l = it2-1;

        if(it1!=g.end()){
          if(it2!=b.end()){
            v.pb((rr-*it1)*(rr-*it1) + (*it2-*it1)*(*it2-*it1)+(rr-*it2)*(rr-*it2));
          }
          if(it2!=b.begin()){
            v.pb((rr-*it1)*(rr-*it1) + (*it2l-*it1)*(*it2l-*it1)+(rr-*it2l)*(rr-*it2l));
          }

        }
        if(it1!=g.begin()){
          if(it2!=b.end()){
            v.pb((rr-*it1l)*(rr-*it1l) + (*it2-*it1l)*(*it2-*it1l)+(rr-*it2)*(rr-*it2));
          }
          if(it2!=b.begin()){
            v.pb((rr-*it1l)*(rr-*it1l) + (*it2l-*it1l)*(*it2l-*it1l)+(rr-*it2l)*(rr-*it2l));
          }
        }


      }
      for (int i = 0; i <ng; i++) {
        ll rr = g[i];

        auto it1 = lower_bound(r.begin(),r.end(),rr);
        auto it2 = lower_bound(b.begin(),b.end(),rr );

        auto it1l = it1-1;
        auto it2l = it2-1;

        if(it1!=r.end()){
          if(it2!=b.end()){
            v.pb((rr-*it1)*(rr-*it1) + (*it2-*it1)*(*it2-*it1)+(rr-*it2)*(rr-*it2));
          }
          if(it2!=b.begin()){
            v.pb((rr-*it1)*(rr-*it1) + (*it2l-*it1)*(*it2l-*it1)+(rr-*it2l)*(rr-*it2l));
          }

        }
        if(it1!=r.begin()){
          if(it2!=b.end()){
            v.pb((rr-*it1l)*(rr-*it1l) + (*it2-*it1l)*(*it2-*it1l)+(rr-*it2)*(rr-*it2));
          }
          if(it2!=b.begin()){
            v.pb((rr-*it1l)*(rr-*it1l) + (*it2l-*it1l)*(*it2l-*it1l)+(rr-*it2l)*(rr-*it2l));
          }
        }


      }
      for (int i = 0; i <nb; i++) {
        ll rr = b[i];

        auto it1 = lower_bound(g.begin(),g.end(),rr);
        auto it2 = lower_bound(r.begin(),r.end(),rr );

        auto it1l = it1-1;
        auto it2l = it2-1;

        if(it1!=g.end()){
          if(it2!=r.end()){
            v.pb((rr-*it1)*(rr-*it1) + (*it2-*it1)*(*it2-*it1)+(rr-*it2)*(rr-*it2));
          }
          if(it2!=r.begin()){
            v.pb((rr-*it1)*(rr-*it1) + (*it2l-*it1)*(*it2l-*it1)+(rr-*it2l)*(rr-*it2l));
          }

        }
        if(it1!=g.begin()){
          if(it2!=r.end()){
            v.pb((rr-*it1l)*(rr-*it1l) + (*it2-*it1l)*(*it2-*it1l)+(rr-*it2)*(rr-*it2));
          }
          if(it2!=r.begin()){
            v.pb((rr-*it1l)*(rr-*it1l) + (*it2l-*it1l)*(*it2l-*it1l)+(rr-*it2l)*(rr-*it2l));
          }
        }


      }

      for (int i = 0; i < v.size(); i++) {
        /* code *///std::cout << v[i] << ' ';
      }//std::cout <<  '\n';
      std::cout << *min_element(v.begin(),v.end()) << '\n';
    }
    return 0;
}
