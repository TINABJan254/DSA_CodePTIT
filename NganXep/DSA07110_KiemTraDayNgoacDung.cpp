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

bool isValid(string s){
	stack<char> st;
	for (char c: s){
		if (c == '(' || c == '[' || c == '{')
			st.push(c);
		else {
			if (st.empty())
				return false;
			if (c == ')' && st.top() != '(')
				return false;
			if (c == ']' && st.top() != '[')
				return false;
			if (c == '{' && st.top() != '}')
				return false;
			st.pop();
		}
	}
	return (st.empty() == true);
}

void solve(){
	string s; cin >> s;
	if (isValid(s))
		cout << "YES\n";
	else
		cout << "NO\n";

}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Note: nhớ kiểm tra stack có rỗng hay không trước khi xét st.top();
Cho một xâu chỉ gồm các kí tự ‘(‘, ‘)’, ‘[‘, ‘]’, ‘{‘, ‘}’. Một dãy ngoặc đúng được định nghĩa như sau:

-     Xâu rỗng là 1 dãy ngoặc đúng.

-     Nếu A là 1 dãy ngoặc đúng thì (A), [A], {A} là 1 dãy ngoặc đúng.

-     Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.

Cho một xâu S. Nhiệm vụ của bạn là xác định xâu S có là dãy ngoặc đúng hay không?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000.

Output: 

Với mỗi test, in ra “YES” nếu như S là dãy ngoặc đúng, in ra “NO” trong trường hợp ngược lại.

Ví dụ:

Input:
2
[()]{}{[()()]()}
[(])

Output
YES
NO
*/
