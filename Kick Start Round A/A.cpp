#include <bits/stdc++.h>
using namespace std;

// Winter is Coming
// What is Dead may never Die
// Sometimes you gotta run before you can walk
// When we hit our lowest point we are open to the greatest change.
// MY GRIEF IS IMMEASURABLE AND MY DAY IS RUINED ;)

#define MOD 1000000007 
#define ll long long
#define fl(n,i) for(ll i=0;i<n;i++)
#define fld(n,i) for(ll i=n-1;i>=0;i--)
#define initA(A,x) memset(A, x, sizeof(A));

void solve(){

    int n,k,x=0;
    string S;

    cin>>n>>k>>S;
    int y=(n/2);
    for(int i=1;i<=y;i++){
        if(S[i-1]!=S[n-i]){
            x++;
        }
    }
    if(x>=k){
        cout<<(x-k)<<"\n";
    }
    else{
        cout<<(k-x)<<"\n";
    }

    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

/*
    "And who are you", the proud lord said,
    "That I must bow so low,
    only a cat of a different coat,
    that's all the truth I know..."

    "In a coat of gold or a coat of red,
    A lion still has claws,
    and mine are long and sharp my lord,
    As long and sharp as yours..."

    And so he spoke, and so he spoke,
    The lord of Castamere,
    And now the rains weep o'er his hall with no one there to hear,
    Yes now the rains weep o'er his hall with not a soul to here.
*/