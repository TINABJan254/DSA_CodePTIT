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
#define pci pair<char, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct cmp {
	bool operator()(const pci& a, const pci& b)
	{
		if(a.se < b.se) return true;
		if(a.se > b.se) return false;
		return a.fi > b.fi;
	}
};

void rearrange(string str, int d){
	//Length of string
	int n = str.length();

	//Store character and fre of all fre
	unordered_map<char, int> m;
	for (int i = 0; i < n; i++){
		m[str[i]]++;
		str[i] = ' ';
	}
	//max-heap
	priority_queue<pci, vector<pci>, cmp> pq(m.begin(), m.end());

	/* Now one by one extract all distinct characters from
    heap and put them back in str[] with the d distance constraint */
	while (pq.empty() == false){
		pci x = pq.top();

		//find the first available pos
		int p = 0;
		while (str[p] != ' '){
			p++;
		}

		//fill x at p, p+d, p+2d,.... p + (fre - 1)*d;
		for (int k = 0; k < x.se; k++){
			//If the index > size, then string cannot be rearranged.
			if (p + d * k >= n){
				cout << "-1\n";
				return;
			}
			str[p + d * k] = x.fi;
		}
		pq.pop();
	}
	cout << "1\n";
	// cout << str << EL;

}

void solve(){
	int d;
	string s;
	cin >> d >> s;
	rearrange(s, d); //greedy algo
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
Cho xâu ký tự S bao gồm các ký tự và số D. 
Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký tự trong S 
để tất cả các ký tự giống nhau đều có khoảng cách là D hay không? 
Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn yêu cầu bài 
toán, ngược lại đưa ra -1.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số D; dòng tiếp theo là xâu S.
T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤D≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
2
ABB
2
AAA

Output
1
-1
*/