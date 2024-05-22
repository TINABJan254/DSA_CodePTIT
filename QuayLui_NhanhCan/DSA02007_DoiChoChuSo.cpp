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
string s, res;

void Init(){
	cin >> k >> s;
	n = s.sz;
	res = s;
}

void Try(int i, string cur_str, int cnt){
	if (cnt > k || i > n){
		return;
	}
	res = max(res, cur_str);
	char max_val = cur_str[i];
	for (int j = i + 1; j <= n; j++){
		max_val = max(max_val, cur_str[j]);
	}
	if (max_val == cur_str[i]){
		Try(i + 1, cur_str, cnt);
	}
	else {
		for (int j = i + 1; j <= n; j++){
			if (cur_str[j] == max_val){
				string tmp = cur_str;
				swap(tmp[i], tmp[j]);
				Try(i + 1, tmp, cnt + 1);
			}
		}
	}
}

void solve(){
	Init();
	Try(0, s, 0);
	cout << res << EL;
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
Cho số tự nhiên K và xâu ký tự các chữ số S.  
Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S. 
Ví dụ K =3 và S = “1234567” ta được “7654321”.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số K; dòng tiếp theo là xâu ký tự S.
T, K, S thỏa mãn ràng buộc: 1≤T ≤100; 1≤K≤10; 1≤.lenght(S)≤7.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input
3
4
1234567
3
3435335
2
1034

Output
7654321
5543333
4301
*/