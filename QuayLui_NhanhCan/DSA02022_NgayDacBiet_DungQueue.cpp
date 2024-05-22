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

void check(string s){
	if (s[0] == '0' && s[1] == '0')
		return;
	if (s[2] == '2' || s[3] == '0')
		return;
	if (s[4] == '0')
		return;
	cout << s[0] << s[1] << "/";
	cout << s[2] << s[3] << "/";
	for (int i = 4; i < s.sz; i++)
		cout << s[i];
	cout << EL;
}

void solve(){
	queue<string> q;
	q.push("0");
	q.push("2");
	while (!q.empty()){
		string u = q.front(); q.pop();
		if (u.sz == 8){
			check(u);
		}
		if (u.sz < 8){
			q.push(u + "0");
			q.push(u + "2");	
		}
	}
}

int main(){
    faster();
	solve();
	return 0;	
}