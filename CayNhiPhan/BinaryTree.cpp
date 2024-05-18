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

struct node{
	int data;
	node *left;
	node *right;
};

node* createNode(int x){
	node *newNode = new node;
	newNode->data = x;
	newNode->left = newNode->right = NULL;
}

void solve(){
	node *root = createNode(1);
//	node *node1 = createNode(5);
//	node *node2 = createNode(2);
//	
//	root->left = node1;
//	root->right = node2;
//	
//	cout << (root->left)->data;	

	root->left = createNode(2);
	root->right = createNode(3);
	(root->left)->left = createNode(4);
	cout << ((root->left)->left)->data;

}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/
