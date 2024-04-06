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
	int n;
	cin >> n;
	int a[n + 5];
	int d[5] = {0};
	for (int i = 0; i < n; i++){
		cin >> a[i];
		d[a[i]]++;
	}

	int res = d[4] + d[2] / 2;
	d[2] %= 2; //co the du 1 nhom 2 nguoi
	res += min(d[1], d[3]); //ghep nhom 3 nguoi voi nhom 1 nguoi

	if (d[1] <= d[3]){
		res += d[3] - d[1] + d[2];
	}
	else {
		d[1] -= d[3];
		if (d[2] != 0){
			//van du 1 nhom 2 nguoi
			if (d[1] <= 2){
				res++;
			}
			else {
				res++;
				d[1] -= 2; //ghep 2 nhom 1 nguoi va 1 nhom 2 nguoi vao 1 xe
				res += d[1] / 4 + min(1, d[1] % 4);
			}
		}
		else {
			res += d[1] / 4 + min(1, d[1] % 4);
		}
	}
	cout << res;

}

int main(){
	faster();
	solve();
	return 0;
}

/*
Chia ra cac truong hop xe taxi co the cho
taxi = 4
taxi = 3 1
taxi = 2 2
taxi = 2 1 1
taxi = 3
taxi = 1 1 1 1

PROB
N nhóm học sinh, mỗi nhóm từ 1-4 người. Các nhóm học
sinh này dự định sẽ đi tham quan vườn bách thú bằng những chiếc xe taxi, 
mỗi xe taxi trở được tôi đa 4 người. Hãy tìm số lượng taxi tối thiểu để có thể chở hết N 
nhóm học sinh này, biết rằng những học sinh ở cùng 1 nhóm sẽ đi cùng taxi

Input format
 Dòng đầu tiên chứa N là số nhóm học sinh
 Dòng thứ 2 gồm N số là số lượng học sinh của N nhóm
Constraints
 1 <= N <= 10000;
 số lượng học sinh mỗi nhóm là dương và <= 4
Output format
 In ra số lượng taxi tối thiểu
Sample
 Input
 	6
 	2 1 3 1 2 2 
 Output
    3
*/