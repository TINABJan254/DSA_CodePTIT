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

ll change(string s){
	ll res = 0;
	for (int i = s.sz - 1; i >= 0; i--)
		if (s[i] == '1'){
			int n = s.sz - i - 1;
			res += (1 << n);
		}
	return res;
}

void solve(){
	string s1, s2; cin >> s1 >> s2;
	cout << change(s1) * change(s2) << EL;
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
Cho hai xâu nhị phân biểu diễn hai số. Nhiệm vụ của bạn là đưa ra tích của hai số. Ví dụ với xâu S1=”1100” và S2=”1010” ta sẽ có kết quả là 120.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 hai xâu nhị phân S1, S2 được viết trên một dòng.
T, S1, S2 thỏa mãn ràng buộc: 1≤T≤100;  1≤ length(S1), length(S2)≤30.
    Output:

Đưa ra tích của mỗi test theo từng dòng.
     Ví dụ:

Input
2
1100 01
01 01

Output
12
1
*/