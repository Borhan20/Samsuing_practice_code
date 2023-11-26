#include<bits/stdc++.h>
using namespace std;

int inf = 1000000;


int recursive(vector<pair<int,int>>v, int hx, int hy, int x, int y, int n,int count,int visited[100]){
	if(count >= n) return abs(hx - x)+abs(hy -y);
	
	int res = inf;
	for(int i=0; i<n; i++){

		int vx = v[i].first;
		int vy = v[i].second;
		if(visited[i]!=1){
			//cout << "fuck"<<endl;
			visited[i]=1;
			res= min(res, recursive(v,hx,hy,vx,vy,n,count+1,visited)+abs(x-vx)+abs(y-vy));
			visited[i]=0;
		}
		
	}
	return res;
}

int main(){

	ios::sync_with_stdio(0), cin.tie(0);

   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
	for(int t=1; t<=20; t++){
		int n;
		cin >> n;
		int hx,hy;
		cin>> hx >> hy;
		int ofx,ofy;
		cin >> ofx >> ofy;
		vector< pair<int, int>> v;
		for(int i=0; i<n; i++ ){
			int a,b;
			cin >> a >> b;
			v.push_back(make_pair(a,b));
		}

		// for(int i=0; i<n; i++){
		// 	cout << v[i].first << " "<<v[i].second <<endl;
		// }
		//cout <<  abs(-2) << endl;
		int visited[100];
		for(int i=0; i<100; i++){
			visited[i]=0;
		}

		
		int res = recursive(v,hx,hy,ofx,ofy,n,0,visited);
		cout << "#" << " " << t << " " << res <<endl;
		v.clear();
	}
}