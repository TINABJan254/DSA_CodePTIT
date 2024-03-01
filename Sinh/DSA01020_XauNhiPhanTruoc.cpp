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

string x;

void Init(){
	cin >> x;
}

void display(){
	cout << x << EL;
}

void genPrev(){
	int i = x.sz - 1;
	while (i >= 0 && x[i] == '0'){
		x[i] = '1';
		--i;
	}

	if (i < 0){
		for (int i = 0; i < x.sz; i++)
			x[i] = '1';
	}
	else{
		x[i] = '0';
	}
}

void solve(){
	Init();
	genPrev();
	display();
}

int main(){
	faster();
	int TC; cin >> TC;
	while(TC--){
		solve();
	}
	return 0;
}

/*
Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân trước của X[]. Ví dụ X[] =”111111” thì xâu nhị phân trước của X[] là “111110”. Với xâu X[] =“000001” thì xâu nhị trước của X[] là “000000”. Chú ý: nếu xâu dữ liệu trong input là xâu đầu tiên thì trước nó sẽ là xâu cuối cùng.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

 Input

2

010101

111111

Output
010100

111110
*/