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

ll gcd (ll a, ll b){
	while (b){
		ll t = a % b;
		a = b;
		b = t;
	}
	return a;
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

struct PS{
	ll tu, mau;
	PS (ll newTu, ll newMau){
		this->tu = newTu;
		this->mau = newMau;
	};
	PS(){};

	void rutGon(){
		ll uc = gcd(this->tu, this->mau);
		this->tu /= uc;
		this->mau /= uc;
	}

	PS operator - (PS b){
		ll mauChung = this->mau * b.mau;
		ll t1 = this->tu * b.mau - this->mau * b.tu;
		PS res(t1, mauChung);

		res.rutGon();	
		return res;
	}	
	~PS(){};
};

void solve(){
	PS a; 
	cin >> a.tu >> a.mau;

	while (a.tu){
		ll x;
		if (a.mau % a.tu == 0){
			x = a.mau / a.tu;
		}
		else{
			x = a.mau / a.tu + 1;
		}

		PS psDonVi(1, x);
		cout << 1 << '/' << x;
		a = a - psDonVi;

		if (a.tu != 0){
			cout << " + ";
		}
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
Ta sẽ đi phân tích ps = 1/x + ps'
	=> muốn có ít phân số nhất thì 1/x phải lớn nhất
	mà 1/x <= ps  -> x >= 1/ps
	tính được x  -> ps' = ps - 1/x
	tiếp tục phân tích ps' như ps tức ps' = 1/x + ps'';
Ví dụ:
	5/6 = 1/x + ps'
	1/x <= 5/6 -> x >= 6/5 -> x >= 2 (x_max = 2) ->  1/x = 6/5
	-> ps' = 5/6 - 1/2 = 1/3
	ps' đã là phân số đơn vị nên ko cần ptich ps' nữa
	vậy: 5/6 = 1/2 + 1/3
PROB:
Một phân số đơn vị nếu tử số của phân số đó là 1. Mọi phân số nguyên dương đều có thể biểu diễn thành tổng các phân số đơn vị. Ví dụ 2/3 = 1/2  + 1/6. Cho phân số nguyên dương P/Q bất kỳ (P < Q), hãy biểu diễn phân số nguyên dương thành tổng phân số đơn vị với số hạng tử là ít nhất.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ đôi tử số P và mẫu số Q của phân số nguyên dương được viết trên một dòng.
T, P, Q thỏa mãn ràng buộc: 1≤T≤100;  1≤P, Q≤100.
Output:

Đưa ra đáp án tìm được trên 1 dòng, theo dạng “1/a + 1/b + …”
Ví dụ:

Input
2
2 3
1 3

Output
1/2 + 1/6 
1/3
*/
