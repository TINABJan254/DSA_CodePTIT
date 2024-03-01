#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n;
int x[1000];
bool final;

void Init();
void display();
void genNext();
void solve();

void Init(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		x[i] = 0;
	final = false;
}

bool checkValid(){
	if (x[1] == 0 || x[n] == 1)
		return false;
	for (int i = 1; i < n; i++)
		if (x[i] == 1 && x[i + 1] == 1)
			return false;
	for (int i = 2; i < n - 1; i++)
		if (x[i - 1] == 0 && x[i] == 0 && x[i + 1] == 0 && x[i + 2] == 0)
			return false;
	return true;
}

void display(){
	for (int i = 1; i <= n; i++)
		if (x[i] == 0)
			cout << '6';
		else
			cout << '8';
	cout << EL;
}

void genNext(){
	int i = n;
	while (i >= 1 && x[i] == 1){
		x[i] = 0;
		--i;
	}
	if (i == 0){
		final = true;
	}
	else{
		x[i] = 1;
	}
}

void solve(){
	Init();
	while (!final){
		if (checkValid())
			display();
		genNext();
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/