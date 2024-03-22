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

int a[100];
int n, k;
int x[100];
vector<vi> res;

void Init(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	res.clear();
}

void Try(int i, int start){
	for (int j = start; j <= n; j++){
		x[i] = a[j];
		if (i == k){
			vi tmp(x + 1, x + i + 1);
			res.pb(tmp);
		}
		else{
			Try(i + 1, j + 1);
		}
	}
}

void solve(){
	Init();	
	sort(a + 1, a + n + 1);
    Try(1, 1);
	sort(res.begin(), res.end());
	for (auto tmp : res){
		for (auto tmp2 : tmp)
			cout << tmp2 << ' ';
		cout << EL;
	}
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
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một và một số K < N.

Hãy liệt kê tất cả các dãy con khác nhau có K phần tử của A[], mỗi dãy đều được sắp xếp theo thứ tự tăng dần.

Các dãy con được liệt kê lần lượt theo thứ tự từ điển.

Input

Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

Dòng đầu ghi hai số N và K (2 < K < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
Output

Với mỗi test, liệt kê tất cả các dãy con thỏa mãn, mỗi dãy con trên một dòng. 

Ví dụ
Input
1
4 3
3 2 5 4

Output
2 3 4
2 3 5
2 4 5
3 4 5
*/