int a[100][100];
int u, n, d[100], e[100], vs[100];

void Dijkstra(int u){
	//Khoi tao
	for (int v = 1; v <= n; v++){
		vs[v] = 0;
		d[v] = a[u][v];
		e[v] = u;
	}
	e[u] = 0; d[u] = 0;
	
	while (1){
		int s = 0, min = INT_MAX;
		for (int i = 1; i <= n; i++){
			if (d[i] < min){
				min = d[i];
				s = i;
			}
		}
		
		if (s == 0)
			return;
		
		vs[s] = 1;
		for (int v = 1; v <= n; v++){
			if (d[v] > d[s] + a[s][v])
				d[v] = d[s] + a[s][v];
				e[v] = s;
		}
	}
}


//bellman-ford
int a[100][100], d[100], e[100];
void bellm(int s){
	//ktao
	for (int v = 1; v <= n; v++){
		d[v] = a[s][v];
		e[v] = s;
	}
	
	d[s] = 0; e[s] = 0;
	
	for (int k = 1; k <= n - 2; k++){
		for (int v = 1; v <= n; v++)
			for (int u = 1; u <= n; u++){
				if (d[v] > d[u] + a[u][v]){
					d[v] = d[u] + a[u][v];
					e[v] = u;
				}
			}
	}
}

//Floyd
int a[100][100], d[100][100], e[100][j];
int n, m;

int Floyd(){
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			d[i][j] = a[i][j]
			e[i][j] = i;
		}
		
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
					e[i][j] = k;
				}
}

//kruskal
vs, d, c, ts;

void kruskal(){
	//sort edge
	for (int i = 1; i <= m - 1; i++)
		for (int j = i + 1; j <= m; j++)
			if (t[i] > t[j])
				swap(edge_j, edge_i);
	
	for (int i = 1; i <= m; i++){
		int u = d[i], v = c[i];
		if (vs[u] == vs[v] && vs[u] != 0)
			continue;
		k++;
		tree.pb(e[i]);
		wt += e.ts;
		
	}
}














