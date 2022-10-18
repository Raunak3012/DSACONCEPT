#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(26,0);
    string Ray;
    cin>>Ray;

    for(int i=0; i<Ray.size(); i++){
        v[Ray[i]-'a']++;
    }
    vector<int> magic;
    int j=0;
    for(int i=0;i<26;i++){
        if(v[i]==0){
            break;
        }
        for(;j<Ray.size();j++ ){
            int x = (int) Ray[j] - (int)'a';
            if(x==i){
                v[x]--;
                magic.push_back(j);
            }
            if(v[x]==0){
                break;
            }
        }
    }
    string Ben = "";
    string Kevin = "";
    //for(int i:magic) cout<<i<<" ";
    j=0;
    for(int i=0;i<Ray.size();i++){
        if(i==magic[j]){
            Kevin = Kevin + Ray[i];
            j++;
        }
        else{
            Ben = Ben + Ray[i];
        }
    }
    for(int i=Ben.size()-1;i>=0;i--){
        Kevin += Ben[i];
    }

    cout<<Kevin<<endl;
    
}