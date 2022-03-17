#include<bits/stdc++.h>
using namespace std;
int main(){
	int r,c;
	cin>>r>>c;
	int a[r][c];
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>a[i][j];
		}
	}
		int r1,c1;
	cin>>r1>>c1;
	int b[r1][c1];
	for(int i=0; i<r1; i++){
		for(int j=0; j<c1; j++){
			cin>>b[i][j];
		}
	}
	if(c !=r1){
		cout<<"NO"<<endl;
		return 0;
	}
	vector<vector<int>>pro(r, vector<int>(c1)); 
	for(int i=0; i<r; i++){
		for(int j=0; j<c1; j++){
		   for(int k=0; k<c; k++){
		   	pro[i][j] +=a[i][k]*b[k][j];
		   }
		}
	}
	for(int i=0; i<pro.size(); i++){
		for(int j=0; j<pro[0].size(); j++){
			cout<<pro[i][j]<<" ";
		}
		cout<<endl;
	}
}