#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string a,b;
        cin>>a>>b;

        set<char> st;
        for(int i=0; i<2; i++){
            st.insert(a[i]);
            st.insert(b[i]);
        }

        int x = st.size();
        cout<<st.size()-1<<endl;
    }
}