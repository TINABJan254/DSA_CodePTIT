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

string s, x;
bool used[100];

void Init(){
	cin >> s;
	x = "";
	memset(used, false, sizeof(used));
}

void display(){
	cout << x << ' ';
}

void Try(){
	for (int i = 0; i < s.sz; i++){
		if (!used[i]){
			x += s[i];
			used[i] = true;
			if (x.sz == s.sz){
				display();
			}
			else
				Try();
			used[i] = false;
			x.pop_back();
		}
	}
}

void solve(){
	Init();
	Try();
	cout << EL;
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
Cho xâu ký tự S bao gồm các ký tự in hoa khác nhau. Hãy đưa ra tất cả các hoán vị của xâu ký tự S. Ví dụ S=”ABC” ta có kết quả {ABC ACB BAC BCA CAB CBA}. 

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên 1 dòng.
T, S thỏa mãn ràng buộc: 1≤T≤10; 1≤length(S) ≤10;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
 
Input
2
AB
ABC

Output
AB BA
ABC ACB BAC BCA CAB CBA 


*/