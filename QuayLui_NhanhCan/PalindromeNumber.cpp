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

string s;
vector<string> v;

bool isPalindrome(string s){
	string tmp = s;
	reverse(tmp.begin(), tmp.end());
	return tmp == s;
}

bool check(){
	for (auto tmp : v)
		if (!isPalindrome(tmp))
			return false;
	return true;
}

void Init(){
	cin >> s;
}

void Try(int pos){
	if (pos == s.sz){
		if (check()){
			for (auto tmp : v)
				cout << tmp << ' ';
			cout << EL;
		}
	}
	for (int j = 0; pos + j < s.sz; j++){
		v.pb(s.substr(pos, j + 1));
		Try(pos + j + 1);
		v.pop_back();
	}
}

void solve(){
	Init();
	v.clear();
	Try(0);
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho số nguyên dương N ko quá 16 chữ số, bạn được phép tách các chữ số của N thành các
số nhỏ hơn và phải đảm bảo các số tách được đều là số thuận nghịch, ko được phép đảo thứ
tự các chữ số của N. Hãy in ra mọi cách tách như vậy.

Input format
Dòng duy nhất chứa N

Output format
In ra các cách tách N thành các số nhỏ hơn thuận nghịch

Constraints
1 <= N <= 10^16

Sample:
Input
282882

Output
2 8 2 8 8 2
2 8 2 88 2
2 8 2882
2 828 8 2
282 8 8 2
282 88 2
*/