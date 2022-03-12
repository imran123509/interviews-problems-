#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	int inv=0;
	int original_place=1;
while(n !=0){

	int original_digit=n%10;
	int inverted_digit=original_place;
	int inverted_place=original_digit;
	inv +=inverted_digit*pow(10, inverted_place-1);
	n /=10;
	original_place++;
}
cout<<inv;
}