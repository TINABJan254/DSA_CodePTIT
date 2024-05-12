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

bool check(string s){
	stack<int> st;
	for (int i = 0; i < s.sz; i++){
		if (s[i] == '(')
			st.push(i);
		else if (s[i] == ')'){
			int j = st.top();
			if (i - j == 2) // TH (x)
				return true; 
			else if (s[j+1] == '(' && s[i-1] == ')')
				return true;
			st.pop();
		}
	}
	return false;
}

void solve(){
	string s; 
	getline(cin, s);
	
	if (check(s))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	int TC; cin >> TC;
	cin.ignore();
	while (TC--){
		solve();
	}
	return 0;
}

/*
Chia là 2 TH: 
	TH1 : dư thừa kiểu (3) + (5)
	TH2 : dư thừa kiểu ((x + y))
Cho biểu thức số học, hãy cho biết biểu thức số học có dư thừa các cặp ký hiệu ‘(’,’) ‘ hay không?

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
Ví dụ:

 

Input

Output

3

((a+b))

(a + (b)/c)

(a + b*(c-d))

Yes

Yes

No
*/
