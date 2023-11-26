#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> cycles;
vector<int>cycle_sum;



void finding_cycle(int graph[100][100],int orange[], int start ,int end,vector<int>list){
	vector<int>cycle;
	int sum = 0;
	for(int i=list.size()-1; i>=0; i--){
		
		cycle.push_back(list[i]);
		sum+=list[i];
		if(list[i]==end) break;
	}
	cycles.push_back(cycle);
	cycle_sum.push_back(sum);
	cycle.clear();


}


void dfs_visit(int graph[100][100], int n, int m, int start,int orange[], int black[],vector<int>list){

	orange[start]=1;

	for(int i=1; i<=n; i++){

		if(graph[start][i]==1 && orange[i]==1 && black[i]!=1){

			finding_cycle(graph,orange, start, i,list);
			//list.pop_back();

		}

		if(graph[start][i]==1 && orange[i]!=1 && black[i]!=1){
			orange[i]=1;
			list.push_back(i);

			dfs_visit(graph,n,m,i,orange,black,list);

			list.pop_back();
			//orange[i]=0;

		}
		
	}
	black[start]=1;

}

void dfs(int graph[100][100], int n, int m, int orange[100], int black[100]){

	for(int start=1; start<=n; start++){
		vector<int>list;

		list.push_back(start);
		dfs_visit(graph,n,m,start,orange,black,list);
		for(int i=0; i<=n; i++){
			orange[i]=0;
			black[i]=0;
		}
		list.clear();
	}

}


int main(){

	ios::sync_with_stdio(0), cin.tie(0);

   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);

	int n,m;
	cin >> n>> m;

	int graph[100][100];

	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			graph[i][j]=0;
		}
	}

	for(int i=0; i<m; i++){
		int a,b;
		cin >>a >> b;
		graph[a][b]=1;
		
	}
	int orange[100];
	int black[100];
	for(int i=0; i<=n; i++){
		orange[i]=0;
		black[i]=0;
	}

	dfs(graph,n,m,orange,black);

	int mini = cycle_sum[0];
	int ind =0;

	for(int i=0; i<cycle_sum.size(); i++){
		if(cycle_sum[i]<mini){
			ind = i;
			mini = cycle_sum[i];
		}
	}

	vector<int>res;
	for(int i=0; i<cycles[ind].size(); i++){
		res.push_back(cycles[ind][i]);
	}
	sort(res.begin(),res.end());
	for(int i=0; i<res.size(); i++){
		if(i>0) cout << " ";
		cout << res[i];
	}
	cout <<endl;
}