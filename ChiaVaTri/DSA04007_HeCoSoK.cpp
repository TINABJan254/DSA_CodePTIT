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

int charToInt(char c){
	return c - '0';
}

void solve(){
	int k;
	string a, b;
	cin >> k >> a >> b;

	if (a.sz < b.sz)
		swap(a, b);
	int lena = a.sz, lenb = b.sz;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	b += string(lena - lenb, '0');
	string res = "";
	int carry = 0; //nho
	for (int i = 0; i < lena; i++){
		int tmp = charToInt(a[i]) + charToInt(b[i]) + carry;
		res += (char)(tmp % k + '0');
		carry = tmp / k;
	}

	if (carry){
		res += (char)(carry + '0');
	}

	reverse(res.begin(), res.end());
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
Cho hai số A, B ở hệ cơ số K. Hãy tính tổng hai số đó ở hệ cơ số K.

Input: Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test ghi 3 số K,A,B.

(2≤K≤10; A và B nếu biểu diễn trong hệ cơ số 10 đều nhỏ hơn 109)

Output: In ra tổng của A và B trong hệ cơ số K
Ví dụ:
Input
1
2 1 10
Output
11
*/