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
        //cout<<i<<" "<<j<<"\n";
        int y1 = j-1, y2 = j+1;
        for(int x=i-1;x>=0;x--){
            if(G[x][j]!=1) break;
            int l = 2*(i-x+1) - (j-y1);
            for(int len=1; y1>=0 && len<=l; len++,y1--){
                if(G[i][y1]==1){
                    if(len==l){
                        res++;
                    }
                }
                else{
                    break;
                }
            }
            int l = 2*(i-x+1) - (y2-j);
            for(int len=1; y2<c && len<=l; len++,y2++){
                if(G[i][y2]==1){
                    if(len==l){
                        res++;
                    }
                }
                else{
                    break;
                }
            }
        }
        int y1 = j-1, y2 = j+1;
        for(int x=i+1;x<r;x++){
            if(G[x][j]!=1) break;
            int l = 2*(i-x+1) - (j-y1);
            for(int len=1; y1>=0 && len<=l; len++,y1--){
                if(G[i][y1]==1){
                    if(len==l){
                        res++;
                    }
                }
                else{
                    break;
                }
            }
            int l = 2*(i-x+1) - (y2-j);
            for(int len=1; y2<c && len<=l; len++,y2++){
                if(G[i][y2]==1){
                    if(len==l){
                        res++;
                    }
                }
                else{
                    break;
                }
            }
        }

        for(int y=j-1;y>=0;y--){
            if(G[i][y]!=1) break;
            int l = 2*(j-y+1);
            for(int x=i-1,len=2; x>=0 && len<=l; len++,x--){
                if(G[x][j]==1){
                    if(len==l){
                        res++;
                    }
                }
                else{
                    break;
                }
            }
            for(int x=i+1,len=2; x<r && len<=l; len++,x++){
                if(G[x][j]==1){
                    if(len==l){
                        res++;
                    }
                }
                else{
                    break;
                }
            }
        }
        for(int y=j+1;y<c;y++){
            if(G[i][y]!=1) break;
            int l = 2*(y-j+1);
            for(int x=i-1,len=2; x>=0 && len<=l; len++,x--){
                if(G[x][j]==1){
                    if(len==l){
                        res++;
                    }
                }
                else{
                    break;
                }
            }
            for(int x=i+1,len=2; x<r && len<=l; len++,x++){
                if(G[x][j]==1){
                    if(len==l){
                        res++;
                    }
                }
                else{
                    break;
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