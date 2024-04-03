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

void solve(){
	int d, s; cin >> s >> d;
	if (d * 9 < s || (s == 0 && d > 0) ){
		cout << "-1\n";
		return;
	}
	--s;
	int min_num[d] = {0};
	for (int i = d - 1; i >= 0; i--){
	    if (s >= 9){
	        min_num[i] = 9;
	        s -= 9;
	    }
	    else {
	        min_num[i] = s;
	        s = 0;
	    }
	}
	min_num[0]++;

	for (int i = 0; i < d; i++)
		cout << min_num[i];
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
Cho hai số nguyên dương S và D, trong đó S là tổng các chữ số và D là số các chữ số của một số. Nhiệm vụ của bạn là tìm số nhỏ nhất thỏa mãn S và D? Ví dụ với S = 9, D = 2 ta có số nhỏ nhất thỏa mãn S và D là 18.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ 2 số S và D được viết trên một dòng.
T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤ S,D≤1000.
Output:

Đưa ra kết quả mỗi test theo từng dòng. Nếu không có đáp án, in ra -1.
Ví dụ:

Input
2
9 2
20 3

Output
18
299
*/