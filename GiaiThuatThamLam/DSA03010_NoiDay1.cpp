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
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		ll x; cin >> x;
		pq.push(x);
	}

	ll OPT = 0;
	while (pq.sz > 1){
		ll First  = pq.top(); pq.pop();
		ll Second = pq.top(); pq.pop();
		OPT += First + Second;
		pq.push(First + Second);
	}
	cout << OPT << EL;
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
Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào số lượng sợi dây N; dòng tiếp theo đưa vào N số A[i] là độ dài của các sợi dây; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤106; 0≤A[i]≤106.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
4
4 3 2 6
5
4 2 7 6 9

Output
29
62
*/