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
int a[100][100];
vector<string> res;
string path;
bool flag;

void Init(){
	cin >> n;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	path = "";
	res.clear();
	flag = false;

}

void Try(int i, int j){
	//cout << i << ' ' << j << EL;
	if (i == n && j == n){
		res.pb(path);
		flag = true;
	}
	else{
		//up
		if (a[i - 1][j] == 1){
			path += "U";
			a[i - 1][j] = 0;
			Try(i - 1, j);
			a[i - 1][j] = 1;
			path.pop_back();
		}
		//left
		if (a[i][j - 1] == 1){
			path += "L";
			a[i][j - 1] = 0;
			Try(i, j - 1);
			a[i][j - 1] = 1;
			path.pop_back();
		}
		//right
		if (a[i][j + 1] == 1){
			path += "R";
			a[i][j + 1] = 0;
			Try(i, j + 1);
			a[i][j + 1] = 1;
			path.pop_back();
		}
		//down
		if (a[i + 1][j] == 1){
			path += "D";
			a[i + 1][j] = 0;
			Try(i + 1, j);
			a[i + 1][j] = 1;
			path.pop_back();
		}
	}
}

void solve(){
	Init();
	if (a[1][1] == 0){
		cout << "-1" << "\n";
		return;
	}
	a[1][1] = 0;
	Try(1, 1);
	if (!flag){
		cout << "-1";
	}
	else {
		sort(res.begin(), res.end());
		for (auto tmp : res)
			cout << tmp << ' ';
	}
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
Nếu xếp thứ tự đi của DLRU thì không cần push vào mảng res để sort nữa
Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:

Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
Left (L): Chuột được phép sang trái dưới nếu ô bên trái nó có giá trị 1.
Up (U): Chuột được phép lên trên nếu ô trên nó có giá trị 1.
Hãy đưa ra tất cả các hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤8; 0≤A[i][j] ≤1.
Output:

Đưa ra các xâu ký tự được sắp xếp, trong đó mỗi xâu là một đường đi của con chuột trong mê cung. In ra đáp án theo thứ tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
Input
3
4
1 0 0 0
1 1 0 1
0 1 0 0
0 1 1 1
4
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
5
1 0 0 0 0
1 1 1 1 1
1 1 1 0 1
0 0 0 0 1
0 0 0 0 1

Output
DRDDRR
DDRDRR DRDDRR
DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD
*/