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
	int sum; cin >> sum;
	int d4 = -1, d7 = -1;
	for (int d7 = sum/7; d7 >= 0; d7--){
		if ( (sum - d7*7) % 4 == 0){
			d4 = (sum - d7*7) / 4;
			break;
		}
	}

	if (d4 != -1){
		for (int i = 0; i < d4; i++)
			cout << 4;
		for (int i = 0; i < d7; i++)
			cout << 7;
	}
	else
		cout << -1;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Số may mắn càng bé thì chứa càng ít số 7, vậy nên ta sẽ đi tìm số chứa ít
chữ số 7 nhất.

PROB
Hoàng yêu thích các số may mắn. Ta biết rằng một số là may mắn 
nếu biểu diễn thập phân của nó chỉ chứa các chữ số là 4 và 7 ví dụ các số 44 744 4 
là số may mắn và 5 17 467 không phải là số may mắn Hoàng muốn tìm số may mắn 
bé nhất có tổng các chữ số bằng n 

Input
Dòng duy nhất chứa số nguyên dương n 
Constraints
 1 <= n <= 10^6

Output 
	in ra đáp án của bài toán Nếu không tồn tại in ra -1 

Sample
Input
 16 

Output
 4444
*/