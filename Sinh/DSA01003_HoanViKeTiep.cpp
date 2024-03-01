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

int n;
int x[1005];

void Init(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
}

void display(){
	for (int i = 1; i <= n; i++)
		cout << x[i] << ' ';
	cout << EL;
}

void genNext(){
	int i = n - 1;
	while (i >= 1 && x[i] > x[i + 1]){
		--i;
	}

	if (i == 0){
		for (int i = 1; i <= n; i++)
			x[i] = i;
	}
	else {
		int pos;
		for (pos = n; pos > i; pos--)
			if (x[pos] > x[i])
				break;
		swap(x[i], x[pos]);

		reverse(x + i + 1, x + n + 1);
	}
}

void solve(){
	Init();
	genNext(); // next permutation
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
Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N. Nhiệm vụ của bạn là đưa ra hoán vị tiếp theo của X[]. Ví dụ N=5, X[] = {1, 2, 3, 4, 5} thì hoán vị tiếp theo của X[] là {1, 2, 3, 5, 4}.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số N; dòng tiếp theo đưa vào hoán vị X[] của 1, 2, .., N.
T, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
*/