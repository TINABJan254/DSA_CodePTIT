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

string path;
vector<string> result;
int a[105][105];
int n;
bool flag = false;

void update(){
	flag = true;
	result.pb(path);
}

void Try(int i, int j){
	if (i == n && j == n){
		update();
	}
	if (a[i + 1][j] == 1){
		path += 'D';
		Try(i + 1, j);
		path.pop_back();
	}
	if (a[i][j + 1] == 1){
		path += 'R';
		Try(i, j + 1);
		path.pop_back();
	}
}

void Init(){
	path.clear();
	result.clear();
	flag = false;
	memset(a, 0, sizeof(a));
}

void solve(){
	Init();
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];	
	}

	if (a[1][1] == 0){
		cout << "-1" << EL;
		return;
	}

	Try(1, 1);

	//result
	if (!flag)
		cout << "-1";
	sort(result.begin(), result.end());
	for (auto x : result)
		cout << x << ' ';
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
Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. 
Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) 
theo nguyên tắc:

Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
Hãy đưa ra một hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.

                        

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤10; 0≤A[i][j] ≤1.
Output:

Đưa ra tất cả đường đi của con chuột trong mê cung theo thứ tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
Input
2
4
1  0  0  0
1  1  0  1 
0  1  0  0 
1  1  1  1
5
1 0 0 0 0
1 1 1 1 1
1 1 0 0 1
0 1 1 1 1
0 0 0 1 1

Output
DRDDRR
DDRDRRDR DDRDRRRD DRDDRRDR DRDDRRRD DRRRRDDD
*/
