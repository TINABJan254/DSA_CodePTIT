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
vector<pii> adj[100005];
bool used[100005];

void Prim(int s){
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	used[s] = true;
	for (pii e : adj[s]){
		if (!used[e.fi]) //cac dinh chua nam trong cay khung
			pq.push({e.se, e.fi});
	}
	
	ll d = 0, cnt = 0;
	while (!pq.empty()){
		//pq.top() : canh co trong so nho nhat
		pii e = pq.top(); pq.pop();
		int w = e.fi, dest = e.se;
		if (!used[dest]){
			++cnt;
			d += w;
			used[dest] = true;
			for (pii tmp : adj[dest]){
				if (!used[tmp.fi])
					pq.push({tmp.se, tmp.fi});
			}
		}
	}
	
	if (cnt == n - 1)
		cout << d << EL;
	else
		cout << "Do thi ko lien thong => khong ton tai cay khung\n";
}

void solve(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
	memset(used, false, sizeof(used));
	Prim(1);
	
	for (int i = 1; i <= n; i++)
	    adj[i].clear();
}

int main(){
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Cho đồ thị vô hướng có trọng số G=<V, E, W>. Nhiệm vụ của bạn là hãy xây dựng một cây khung nhỏ nhất của 
đồ thị bằng thuật toán Prim.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào hai số V, E tương ứng với số đỉnh và số cạnh của đồ thị; phần thứ 2 đưa vào E cạnh của đồ thị, mỗi cạnh là một bộ 3: đỉnh đầu, đỉnh cuối và trọng số của cạnh.
T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤V≤100; 1≤E, W≤10000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
3 3
1 2 5
2 3 3
1 3 1
2 1
1 2 5

Output
4
5
*/