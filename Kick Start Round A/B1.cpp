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

    vector<pair<int,int>> V;

    fl(r,i){
        fl(c,j){
            cin>>G[i][j];
        }
    }

    fl(r,i){
        fl(c,j){
            bool b = false;
            if(G[i][j]==1){
                if(i>0){
                    if(G[i-1][j]==1){
                        if(j>0){
                            if(G[i][j-1]==1){
                                b = true;
                            }
                        }
                        if(j<(c-1)){
                            if(G[i][j+1]==1){
                                b = true;
                            }
                        }
                    }
                }
                if(i<(r-1)){
                    if(G[i+1][j]==1){
                        if(j>0){
                            if(G[i][j-1]==1){
                                b = true;
                            }
                        }
                        if(j<(c-1)){
                            if(G[i][j+1]==1){
                                b = true;
                            }
                        }
                    }
                }
                
            }
            if(b) V.push_back(make_pair(i,j));
        }
    }

    

    for(pair<int,int> p : V){
        int i = p.first, j = p.second;
        
        int l1 = 1, l2 = 1, l3 = 1, l4 = 1;
        for(int x=i+1;x<r;x++){
            if(G[x][j]==1){
                l1++;
            }
            else{
                break;
            }
        }
        for(int x=i-1;x>=0;x--){
            if(G[x][j]==1){
                l2++;
            }
            else{
                break;
            }
        }
        for(int y=j+1;y<c;y++){
            if(G[i][y]==1){
                l3++;
            }
            else{
                break;
            }
        }
        for(int y=j-1;y>=0;y--){
            if(G[i][y]==1){
                l4++;
            }
            else{
                break;
            }
        }
        

        for(int x=i+1;x<r;x++){
            int l = 2*(x-i+1);
            if(G[x][j]==1){
                if(l3>=l){
                    res++;
                }
                if(l4>=l){
                    res++;
                }
            }
            else{
                break;
            }
        }
        for(int x=i-1;x>=0;x--){
            int l = 2*(i-x+1);
            if(G[x][j]==1){
                if(l3>=l){
                    res++;
                }
                if(l4>=l){
                    res++;
                }
            }
            else{
                break;
            }
        }
        for(int y=j+1;y<c;y++){
            int l = 2*(y-j+1);
            if(G[i][y]==1){
                if(l2>=l){
                    res++;
                }
                if(l1>=l){
                    res++;
                }
            }
            else{
                break;
            }
        }
        for(int y=j-1;y>=0;y--){
            int l = 2*(j-y+1);
            if(G[i][y]==1){
                if(l2>=l){
                    res++;
                }
                if(l1>=l){
                    res++;
                }
            }
            else{
                break;
            }
        }
        //cout<<i<<" "<<j<<" "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<res<<"\n";
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