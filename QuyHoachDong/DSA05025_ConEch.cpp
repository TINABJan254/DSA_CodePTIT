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

void solve(){
	int n; cin >> n;
	ll F[100] = {0};
	F[0] = 1;
	F[1] = 1;
	F[2] = 2;
	for (int i = 3; i <= n; i++)
		F[i] = F[i - 1] + F[i - 2] + F[i - 3];
	cout << F[n] << EL;
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
Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến. 
Hãy đếm số các cách con ếch có thể nhảy đến đỉnh.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là số n là số bước con ếch có thể lên 
được đỉnh.
T, n thỏa mãn ràng buộc: 1≤T≤100;  1≤n ≤50.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
1
5

Output
1
13
*/