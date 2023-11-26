#include<bits/stdc++.h>
using namespace std;

int inf = 100000;

int min_distance(int dist[],bool visited[],int n){
	int min_index;
	int min_dis = inf;
	for(int i=0;  i<n; i++){
		if(dist[i]!=inf && visited[i]==false && dist[i]<min_dis){
			min_dis = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

int dijktra(int mat[100][100],int n, int src){
	int dist[n+1];
	bool visited[n+1];

	for(int i=0; i<n; i++){
		dist[i]=inf;
		visited[i]=false;
	}

	dist[src]=0;

	
	for(int i=0; i<n-1; i++){

		int u = min_distance(dist,visited,n);
		//cout << u << endl;

		visited[u]=true;

		for(int i=0; i<n; i++){

			if(dist[u]+mat[u][i]< dist[i] && visited[i]==false){
				dist[i]=dist[u]+mat[u][i];
				

			}
			//cout << u<< " "<< i << " "<<dist[i]<<endl;

		}

		
	}

	for(int i=0; i<n; i++){
		cout << i+1 << "th node"<< " " << dist[i]<<endl;
	}

	return 0;

}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);

   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
	int n;
	int e;
	cin >> n>> e;
	int mat[100][100];
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			mat[i][j]=inf;
		}
	}
	for(int i=0; i<e; i++){
		int a, b,c;
		cin >> a >> b >> c;
		mat[a-1][b-1]=c;
		mat[b-1][a-1]=c;
	}
	int res = dijktra(mat,n,0);
}