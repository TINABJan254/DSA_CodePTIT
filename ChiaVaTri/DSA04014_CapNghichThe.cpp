//Count Inversion
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

ll merge(ll *a, int L, int mid, int R){
	vi v1(a + L, a + mid + 1);
	vi v2(a + mid + 1, a + R + 1);

	int i = 0, j = 0;
	ll cnt = 0;
	while (i < v1.sz && j < v2.sz){
		if (v1[i] <= v2[j]){
			a[L++] = v1[i++];
		}
		else {
			a[L++] = v2[j++];
			cnt += v1.sz - i; //cac phan tu trong v1 tu i -> (v1.sz - 1)
		}
	}

	while (i < v1.sz)
		a[L++] = v1[i++];
	while (j < v2.sz)
		a[L++] = v2[j++];

	return cnt;
}

ll mergeSort(ll *a, int L, int R){
	if (L < R){
		int mid = (L + R)/2;
		ll res = 0;
		res += mergeSort(a, L, mid);
		res += mergeSort(a, mid + 1, R);
		res += merge(a, L, mid, R);
		return res;
	}
	return 0;
}

void solve(){
	int n; cin >> n;
	ll a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << mergeSort(a, 0, n - 1) << EL; //count Inversion
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
Cho mảng A[] gồm N phần tử. Ta gọi cặp nghịch thế của mảng A[] là số các cặp i, j sao cho i<j và A[i]>A[j]. Đối với mảng đã được sắp xếp thì số cặp nghịch thế bằng 0. Mảng đã sắp theo thứ tự giảm dần có số đảo ngược cực đại. Nhiệm vụ của bạn là hãy đưa ra số cặp nghịch thế của mảng A[] gồm N phần tử.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N tương ứng với số phần tử của mảng A[]; phần thứ 2 là N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤106; 1≤A[i]≤1018.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
5
2 4 1 3 5
5
5 4 3 2 1

Output
3
10
*/