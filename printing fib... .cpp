#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	int a=0;
	int b=1;
	for(int i=0; i<n; i++){
		cout<<a<<" ";
		int c=a+b;
		a=b;
		b=c;
	}cout<<endl;

}