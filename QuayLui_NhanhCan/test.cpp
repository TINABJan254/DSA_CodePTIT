#include<bits/stdc++.h>
using namespace std;
int x[2] = {1,0};
int y[2] = {0,1};
int a[100][100]; int n; bool oke;
vector<int> v;


void Init(){
	oke = false;
	cin >> n;
	v.clear();
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
}
void Display(){
	oke = true;
	for(int i=0;i<v.size();i++){
		if(v[i] == 0) cout << 'D';
		else cout << 'R';
	}
	cout << " ";
}

void Try(int i, int j){
	for(int k=0;k<=1;k++){
		if(a[i + x[k]][j + y[k]] == 1){
			v.push_back(k);
			if(i+x[k]==n && j+y[k]==n){
				Display();
			}
			else{
				Try(i+x[k],j+y[k]);
			}
			v.pop_back();
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		Init();
		if (a[1][1] == 0){
			cout << -1 << endl;
			continue;
		}

		Try(1,1);
		if(!oke) cout << -1;
		cout << endl;
	}
	return 0;
}