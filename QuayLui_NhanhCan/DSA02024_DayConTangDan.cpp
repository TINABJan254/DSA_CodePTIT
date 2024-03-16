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
int a[100];
int x[100];
vector<string> res;

void Init(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	res.clear();
}

void apply(int num){
	string tmp = "";
	for (int j = 1; j <= num; j++){
		tmp += to_string(x[j]);
		tmp += " ";
	}
	res.pb(tmp);
}

void Try(int i, int start){
	for (int j = start; j <= n; j++){
		if (a[j] > x[i - 1]){
			x[i] = a[j];
			if (i >= 2){
				apply(i);
			}
			Try(i + 1, j + 1);
		}
	}
}

void solve(){
	Init();
	x[0] = -1;
	Try(1, 1);
	sort(res.begin(), res.end());
	for (auto tmp : res)
		cout << tmp << EL;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho dãy số a[] có n phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các dãy con có từ 2 phần tử trở lên của dãy a[] thỏa mãn tính chất tăng dần.

Dãy con tạo được bằng cách lấy ra các phần tử trong dãy a[] nhưng vẫn giữ nguyên thứ tự ban đầu.

Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống, hãy liệt kê theo thứ tự từ điển.

Input

Dòng đầu ghi số n (không quá 20)
Dòng thứ 2 ghi n số của dãy a[]. Các số khác nhau từng đôi một và có giá trị không quá 100.
Output

Ghi ra lần lượt các dãy con tăng dần theo thứ tự từ điển.

Ví dụ

Input
4
6 3 7 11

Output
3 11
3 7
3 7 11
6 11
6 7
6 7 11
7 11
*/