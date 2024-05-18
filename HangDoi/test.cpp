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

vector<string> res;

void Init(){
	queue<string> q;
	q.push("1");
	q.push("2");
	q.push("3");
	q.push("4");
	q.push("5");
	while (!q.empty()){
		string u = q.front(); q.pop();
		if (u.sz > 5)
			break;
		res.pb(u);
		int d[10];
		memset(d, 0, sizeof(d));
		for (char c : u)
			d[c - '0'] = 1;
		for (int i = 0; i <= 5; i++)
			if (d[i] == 0)
				q.push(u + to_string(i));
	}
}

void solve(){
	int L, R; cin >> L >> R;
	int cnt = 0;
	for (string x : res)
		if (stoi(x) >= L && stoi(x) <= R)
			++cnt;
			//cout << x << " ";
	cout << cnt << EL;
}

int main(){
	faster();
	Init();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Cho hai sá»‘ nguyÃªn L, R. HÃ£y Ä‘Æ°a ra sá»‘ cÃ¡c sá»‘ K nguyÃªn dÆ°Æ¡ng trong khoáº£ng [L, R] thá»a mÃ£n Ä‘iá»u kiá»‡n: â€¢ Táº¥t cáº£ cÃ¡c chá»¯ sá»‘ cá»§a K Ä‘á»u khÃ¡c nhau. â€¢ Táº¥t cáº£ cÃ¡c chá»¯ sá»‘ cá»§a K Ä‘á»u nhá» hÆ¡n hoáº·c báº±ng 5. VÃ­ dá»¥ vá»›i L = 4, R = 13 ta cÃ³ 5 sá»‘ thá»a mÃ£n yÃªu cáº§u lÃ  4, 5, 10, 12, 13,
Input Format
â€¢ DÃ²ng Ä‘áº§u tiÃªn Ä‘Æ°a vÃ o sá»‘ lÆ°á»£ng test T. â€¢ DÃ²ng tiáº¿p theo Ä‘Æ°a vÃ o cÃ¡c bá»™ test. Má»—i bá»™ test Ä‘Æ°á»£c lÃ  má»™t cáº·p L, R Ä‘Æ°á»£c viáº¿t trÃªn má»™t dÃ²ng.
Constraints
â€¢ T, L, R thá»a mÃ£n rÃ ng buá»™c: 1â‰¤Tâ‰¤100; 0â‰¤Lâ‰¤Râ‰¤10^5.
Output Format
â€¢ ÄÆ°a ra káº¿t quáº£ má»—i test theo tá»«ng dÃ²ng.
Sample Input 0
8
9 41
91 163
28 59
12 38
72 127
48 68
50 101
22 100
Sample Output 0
17
20
15
14
8
5
5
18

*/