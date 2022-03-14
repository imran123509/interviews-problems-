#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(0);
int n, k;
cin>>n>>k;
int div=1, mul=1;
int number_of_digites=0;
int temp=n;
while(temp>0){
	temp /=10;
	number_of_digites++;
}
k=k%number_of_digites;
if(k<0){
	k=k+number_of_digites;
}
for(int i=1; i<=number_of_digites; i++){
	if(i<=k){
		div=div*10;
	}else{
		mul=mul*10;
	}
}
int q=n/div;
int r=n%div;
int ans=r*mul+q;
cout<<ans<<endl;
}