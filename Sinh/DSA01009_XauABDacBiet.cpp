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

// 0 = A, 1 = B

int x[1005];
int n, k;
bool final;

void Init(){
	cin >> n >> k;
	memset(x, 0, sizeof(x));
	final = false;
}

bool check(){
	int num = 0;
	for (int i = 1; i <= n; i++){
		if (x[i] == 0){
			int cnt = 0;
			while (i <= n && x[i] == 0){
				++cnt;
				++i;
			}
			if (cnt > k)
				return false;
			else if (cnt == k)
				++num;
		}
	}
	return num == 1;
}

void display(vi v){
	for (auto tmp : v){
		if (tmp == 0)
			cout << "A";
		else
			cout << "B";
	}
}

void genNext(){
	int i = n;
	while (i >= 1 && x[i] == 1){
		x[i] = 0;
		--i;
	}

	if (i == 0){
		final = true;
	}
	else {
		x[i] = 1;
	}
}

void solve(){
	Init();
	vector<vi> res;
	while (!final){
		if (check()){
			vi tmp(x + 1, x + n + 1);
			res.pb(tmp);
		}
		genNext();
	}

	cout << res.sz << EL;
	for (auto tmp : res){
		display(tmp);
		cout << EL;
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Một xâu kí tự S = (s1, s2, .., sn) được gọi là xâu AB độ dài n nếu với mọi siÎS thì si hoặc là kí tự A hoặc si là kí tự B . Ví dụ xâu S = “ABABABAB” là một xâu AB độ dài 8. Cho số tự nhiên N và số tự nhiên K (1£K<N£15 được nhập từ bàn phím), hãy viết chương trình liệt kê tất cả các xâu AB có độ dài N chứa duy nhất một dãy K kí tự A liên tiếp.

Dữ liệu vào chỉ có một dòng ghi hai số N và K.

Kết quả ghi ra màn hình theo khuôn dạng:

Dòng đầu tiên ghi lại số các xâu AB thỏa mãn yêu cầu bài toán;
Những dòng kế tiếp, mỗi dòng ghi lại một xâu AB thỏa mãn. Các xâu được ghi ra theo thứ tự từ điển.


INPUT
5 3 

OUTPUT
5
AAABA
AAABB
ABAAA
BAAAB
BBAAA
*/