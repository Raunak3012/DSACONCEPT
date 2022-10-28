#include <bits/stdc++.h>
using namespace std;

int main(){
	
	stack<int> S;
	S.push(1);
	cout<<"size after pushing : "<<S.size()<<"\n";
	cout<<"Top of the stack : "<<S.top()<<"\n";
	
	S.pop();
	
	cout<<"size after popping : "<<S.size()<<"\n";
	
	return 0;
	
}
