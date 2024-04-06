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

void merge(int *a, int L, int mid, int R){
	vector<int> v1(a + L, a + mid + 1);
	vector<int> v2(a + mid + 1, a + R + 1);

	int i = 0, j = 0;
	while (i < v1.sz && j < v2.sz){
		if (v1[i] <= v2[j]){
			a[L++] = v1[i++];
		}
		else{
			a[L++] = v2[j++];
		}
	}

	while (i < v1.sz){
		a[L++] = v1[i++];
	}
	while (j < v2.sz){
		a[L++] = v2[j++];
	}
}

void mergeSort(int *a, int L, int R){
	if (L < R){
		int mid = (L + R) / 2;
		mergeSort(a, L, mid);
		mergeSort(a, mid + 1, R);
		merge(a, L, mid, R);
	}
}

void solve(){
	int n;
	cin >> n;
	int a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	mergeSort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << EL;
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
Cho mảng A[] gồm N phần tử chưa được sắp xếp. Nhiệm vụ của bạn là sắp xếp các phần tử của mảng A[] theo thứ tự tăng dần bằng thuật toán Merge Sort.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N tương ứng với số phần tử của mảng A[]; phần thứ 2 là N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N, A[i]≤106.
Output:

Đưa ra kết quả các test theo từng dòng.
Input
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1

Output
1 3 4 7 9
1 2 3 4 5 6 7 8 9 10
*/