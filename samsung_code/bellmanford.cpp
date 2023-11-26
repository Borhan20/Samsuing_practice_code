#include<bits/stdc++.h>
using namespace std;

int inf = 100000;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, e;
	cin >> n>> e;
	vector<vector<int>>v;
	for(int i=0; i<e; i++){
		int a,b,w;
		vector<int>test;
		cin >> a>> b >> w;

		test.push_back(a-1);
		test.push_back(b-1);
		test.push_back(w);


		v.push_back(test);
		test.clear();
		test.push_back(b-1);
		test.push_back(a-1);
		test.push_back(w);
		v.push_back(test);
		test.clear();
		
	}

	int dist[100];
	
	for(int i=0; i<100; i++) dist[i]=inf;

	dist[0]=0;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<2*e-1; j++){
			//cout << dist[v[j][0]]<< " " << v[j][0]<< " "<<v[j][1] <<endl;
			if(dist[v[j][0]]+v[j][2] < dist[v[j][1]] ){
				dist[v[j][1]]=dist[v[j][0]]+v[j][2];
			}

		}
	}

	for(int i=0; i<n; i++){
		cout << i+1 << "th node"<< " "<< dist[i]<<endl; 
	}
}