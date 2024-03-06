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
int root[1005];
bool final;

void Init(){
	cin >> n >> k;
	set<int> s;
	for (int i = 1; i <= n; i++){
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}
	int idx = 1;
	for (auto tmp : s)
		root[idx++] = tmp;
	n = s.sz;
	for (int i = 1; i <= k; i++)
		x[i] = i;
	final = false;
}

void display(){
	for (int i = 1; i <= k; i++)
		cout << root[x[i]] << " ";
	cout << EL;
}

void genNext(){
	int i = k;
	while (i >= 1 && x[i] == n-k+i){
		--i;
	}

	if (i == 0){
		final = true;
	}
	else {
		x[i++]++;
		for (i; i <= k; i++)
			x[i] = x[i - 1] + 1;
	}
}

void solve(){
	Init();
	while (!final){
		display();
		genNext();
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho dãy số A[] có N phần tử. Hãy liệt kê tất cả các tổ hợp chập K của tập các phần tử khác nhau trong A[]. Các tổ hợp cần liệt kê theo thứ tự từ điển (tức là trong mỗi tổ hợp thì giá trị từ nhỏ đến lớn, và tổ hợp sau lớn hơn tổ hợp trước).

Input

Dòng đầu ghi hai số N và K.

Dòng thứ 2 ghi N số của mảng A[]. Các giá trị không quá 1000.

Dữ liệu đảm bảo số phần tử khác nhau của A[] không quá 20 và K không quá 10.

Output

Ghi ra lần lượt các tổ hợp tìm được, mỗi tổ hợp trên một dòng.

Ví dụ

Input



8 3

2 4 4 3 5 1 3 4

Output
1 2 3

1 2 4

1 2 5

1 3 4

1 3 5

1 4 5

2 3 4

2 3 5

2 4 5

3 4 5
*/