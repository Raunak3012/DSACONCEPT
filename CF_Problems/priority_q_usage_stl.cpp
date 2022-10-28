// think well and correct, code well and correct...
// if one approach is stuck try to think of other approaches, 
// observe patterns through examples etc.
// and duirng a contest/interview, 
// try doing the above  as fast as possible


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pf push_front
#define pb push_back

const ll MX = (ll)1e6;

ll gcd(ll a, ll b){
  if (b == 0){ return a; }
  return gcd(b, a % b);
}
////////////////////////////////////////////////
// FOR C++ STL

struct cmp{
  bool operator()(const pair<int,int> &a,const pair<int,int> &b ){
    int lena = a.second - a.first + 1;
    int lenb = b.second - b.first + 1;
    if (lena == lenb) return a.first > b.first;
    return lena < lenb;
    }
};

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    ll t;
    cin>>t;
    while (t--) {
      /* code */
      ll n;
      cin>>n;

      priority_queue< pair<int,int>, vector<pair<int,int>>, cmp > pq;

      pq.push({0,n-1});

      ll arr[n] ={0};
      for(int i=0;i<n;i++){
        ll l = (pq.top()).first;
        ll r = (pq.top()).second;
        pq.pop();
        ll mid;
        if((r-l+1)%2!=0){
          mid = (l+r)/2;
          arr[(l+r)/2] = i+1;
        }
        else{
          mid = (l+r-1)/2;
          arr[(l+r-1 )/2 ] = i+1;
        }

        pq.push({l,mid-1});
        pq.push({mid+1,r});

      }
      for(int i=0;i<n;i++){
        std::cout << arr[i] << ' ';
      }
      std::cout  << '\n';
    }

    return 0;
}




/*
ll n,m;
cin>>n>>m;

std::vector<int> Nmx; std::vector<int> Mmx;
ll N = n;
ll M = m;
while (N>0) {
  Nmx.pb(N%7);//+ Nmx;
  N/=7;
}
while (M>0) {
  Mmx.pb(M%7);//+ Mmx;
  M/=7;
}

ll ans = 0;

if(Nmx.size() +Mmx.size() <=7 ){
  for (size_t i = 0; i < n; i++) {
    bool arr[7];
    for (size_t j = 0; j < 7; j++) {
      arr[j] = false;
    }
    bool st1 = true;
    ll f1 = 0;
    while (i>0) {
      if(arr[(i%7)]==false)
        arr[(i%7)] = true;
      else
        st1 = false;
        break;//+ Nmx;
      f1++;
      i/=7;
    }
    if(i==0){
      arr[0] = true;
      f1++;
    }
    if(Nmx.size() > f1  and arr[0] == true)
      st1 = false;
    if(st1)
      continue;
    for (size_t j = 0; j < m; j++) {
      bool sta = true;
      ll f2 = 0;
      while (j>0) {
        if(arr[(j%7)]==false)
          arr[(j%7)] = true;
        else{
          sta = false; break; }//+ Nmx;
        f2++;
        j/=7;
      }
      if(j==0 ){
        f2++;
      }
      if(Mmx.size() > f2  and arr[0] == true)
        sta = false;

      if(sta){
        ans++;
      }
    }
  }

}

std::cout << ans << '\n';
//reverse(Nmx.begin(),Nmx.end());
*/
