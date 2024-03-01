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

int n, k;
int x[1005];

void Init(){
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		cin >> x[i];
}

void display(){
	for (int i = 1; i <= k; i++)
		cout << x[i] << ' ';
	cout << EL;
}

void genNext(){
	int i = k;
	while (i >= 1 && x[i] == n-k+i){
		--i;
	}

	if (i == 0){
		for (int i = 1; i <= k; i++)
			x[i] = i;
	}
	else {
		x[i++]++;
		for (i; i <= k; i++)
			x[i] = x[i - 1] + 1;
	}
}

void solve(){
	Init();
	genNext();
	display();
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
Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N. Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử tiếp theo của X[]. Ví dụ N=5, K=3, X[] ={2, 3, 4} thì tập con tiếp theo của X[] là {2, 3, 5}.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.
T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
*/