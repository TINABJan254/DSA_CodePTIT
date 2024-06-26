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
vector<string> res;
string x;
string root = "()[]{}";

bool check(string s){
	stack<char> st;
	for (char c : s){
		if (c == '(' || c == '[' || c == '{')
			st.push(c);
		else{
			if (st.empty())
				return false;
			if (st.top() == '(' && c != ')')
				return false;
			if (st.top() == '[' && c != ']')
				return false;
			if (st.top() == '{' && c != '}')
				return false;
			st.pop();
		}
	}
	return st.empty();
}

void Try(){
	for (char c : root){
		x.pb(c);
		if (x.sz == n){
			if (check(x))
				res.pb(x);
		}
		else 	
			Try();
		x.pop_back();
	}
}

void solve(){
	cin >> n;
	Try();
	sort(res.begin(), res.end());
	for (auto tmp : res)
		cout << tmp << ' ';
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	solve();
	return 0;
}

/*


*/
