#include<bits/stdc++.h>
using namespace std;
vector<int> NGE(vector<int> &v){
	vector<int>nge(v.size());

	stack<int>s;
	for(int i=0; i<v.size(); i++){
		while(!s.empty() && v[i]>v[s.top()]){
			nge[s.top()]=i;
			s.pop();
		}
		s.push(i);
		}
		while(!s.empty()){
			nge[s.top()]=-1;
			s.pop();
		}
	
	return nge;
}
int main(){
int n;
cin>>n;
vector<int> a(n);
for(int i=0; i<n; i++){
	cin>>a[i];
}
vector<int>nge=NGE(a);
for(int i=0; i<n; i++){
	cout<<a[i]<<" "<<(nge[i]==-1 ? -1 : a[nge[i]])<<endl;
}

}

//https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem