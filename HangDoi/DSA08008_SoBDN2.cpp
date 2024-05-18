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

bool isDivisible(string s, int n){
	int mod = 0;
	for (int i = 0; i < s.sz; i++){
		mod = mod * 10 + (s[i] - '0') % n;
		mod %= n;
	}
	
	return mod == 0;
}

void solve(){
	int n; cin >> n;
	queue<string> q;
	vector<string> res;
	q.push("1");
	while (true){
		string u = q.front(); q.pop();
		if (isDivisible(u, n)){
			cout << u << EL;
			return;
		}
		q.push(u + "0");
		q.push(u + "1");
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
Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. 
Ví dụ số K =  101 là số BDN, k=102 không phải là số BDN.

Số BDN của N là số P =M*N sao cho P là số BDN. Cho số tự nhiên N (N<1000), hãy tìm số BDN nhỏ nhất của N.

Ví dụ. Với N=2, ta tìm được số BDN của N là P = 5*2=10. N = 17 ta tìm được số BDN của 17 là P = 653*17=11101.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số tự nhiên N.
          Output:

                        Đưa ra kết quả mỗi test theo từng dòng.

          Ví dụ:

 

Input
3
2
12
17
10

Output
11100
11101
*/
