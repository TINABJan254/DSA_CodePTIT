#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, m;
int parent[1005], Sz[1005];

void make_set(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		parent[i] = i;
		Sz[i] = 1;
	}
		
}

//Di tim dai dien cho dinh u
int find_set(int u){
	if (u == parent[u])
		return u;
	return parent[u] = find_set(parent[u]);
	/*
	int p = find_set(parent[u]);
	parent[u] = p;
	return p;
	*/
}

bool union_sets(int x, int y){
	x = find_set(x);
	y = find_set(y);
	if (x != y){ 
		if (Sz[x] < Sz[y]) swap(x, y);
		parent[y] = x; //Chon dai dien cua tap co nhieu phan tu hon lam dai dien cho tap con lai
		Sz[x] += Sz[y];
		return true;
		/*
		if (Sz[x] > Sz[y]){
			parent[y] = x;
			Sz[x] += Sz[y];
		}
		else{
			parent[x] = y;
			Sz[y] += Sz[x];
		}
		*/
	}
	return false;
}

void solve(){
	make_set();
}

int main(){
	faster();
	solve();
	return 0;
}

/*
DSU chỉ áp dụng cho đồ thị vô hướng
DSU sẽ có 2 thao tác đó là 
	Union : gộp 2 đỉnh thành 1 tập hợp (thực chất phép gộp 2 đỉnh tức là gộp 2 tập hợp chứa 2 đỉnh đó)
	Find  : tìm đại diện cho 1 đỉnh
*/
