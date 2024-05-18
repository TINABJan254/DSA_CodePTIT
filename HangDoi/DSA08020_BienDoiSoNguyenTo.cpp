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

bool used[10005];
bool prime[10005];
int s, t;

void sieve(){
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= 100; i++){
		if (prime[i]){
			for (int j = i * i; j <= 10005; j += i)
				prime[j] = false;
		}
	}
}

int BFS(){
	queue<pii> q;
	q.push({s, 0});
	used[s] = true;
	while (!q.empty()){
		int u = q.front().fi;
		int len = q.front().se;
		q.pop();
		if (u == t)
			return len;
		for (int i = 0; i < 4; i++){
			string tmp = to_string(u);
			char st = '0';
			if (i == 0) st = '1';
			for (char c = st; c <= '9'; c++){
				tmp[i] = c;
				if (!used[stoi(tmp)] && prime[stoi(tmp)]){
					q.push({stoi(tmp), len + 1});
					used[stoi(tmp)] = true;
				}
			}
		}
	}
	
	return -1;
}

void solve(){
	cin >> s >> t;
	memset(used, false, sizeof(used));
	cout << BFS() << EL;
}

int main(){
	faster();
	sieve();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Cho cặp số S và T là các số nguyên tố có 4 chữ số (Ví dụ S = 1033, T = 8197 là các số nguyên tố có 4 chữ số). Hãy viết chương trình tìm cách dịch chuyển S thành T thỏa mãn đồng thời những điều kiện dưới đây:

Mỗi phép dịch chuyển chỉ được phép thay đổi một chữ số của số ở bước trước đó (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1733 là hợp lệ);
Số nhận được cũng là một số nguyên tố có 4 chữ số (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1833 là không hợp lệ, và S dịch chuyển thành 1733 là hợp lệ);
Số các bước dịch chuyển là ít nhất.
Ví dụ số các phép dịch chuyển ít nhất để S = 1033 thành  T = 8179 là 6 bao gồm các phép dịch chuyển như sau:       

8179 ß 8779ß 3779ß 3739ß 3733ß 1733ß 1033.

Input:

Dòng đầu tiên đưa vào số lượng test T (T≤100)
Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là một bộ đôi S, T.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:
Input
2
1033 8179
1033 8779

Output
6
5
*/
