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

    int r,c;
    ll res = 0;

    cin>>r>>c;

    int G[r][c];

    fl(r,i){
        fl(c,j){
            cin>>G[i][j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(j<(c-1)){
                int l = G[i][j] - G[i][j+1];
                if(l>1){
                    res += l-1;
                    G[i][j+1] += (l-1);
                }
                if(l<-1){
                    res += -l-1;
                    G[i][j] += -l-1;
                }
            }
        }
    }


    for(int j=0;j<c;j++){
        for(int i=0;i<r;i++){
            if(i<(r-1)){
                int l = G[i][j] - G[i+1][j];
                if(l>1){
                    res += l-1;
                    G[i+1][j] += (l-1);
                }
                if(l<-1){
                    res += -l-1;
                    G[i][j] += -l-1;
                }
            }
        }
    }

    cout<<res<<"\n";    

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