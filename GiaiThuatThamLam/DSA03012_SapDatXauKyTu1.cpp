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
#define pci pair<char, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	string s; cin >> s;
	int max_fre = INT_MIN;
	int fre[256] = {0};
	for (auto c : s){
		fre[c]++;
		max_fre = max(max_fre, fre[c]);
	}
	int n = s.sz;
	if (max_fre <= ((n-1)/2 + 1) ) //n - max_fre + 1
		cout << 1 << EL;
	else
		cout << -1 << EL;
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
Cho xâu ký tự S bao gồm các ký tự in thường. Nhiệm vụ của bạn là kiểm tra 
xem ta có thể sắp đặt lại các ký tự trong S để hai ký tự giống nhau đều 
không kề nhau hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S 
thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên một dòng.
T, S thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
3
geeksforgeeks
bbbabaaacd
bbbbb

Output
1
1
-1
*/