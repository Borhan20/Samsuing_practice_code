#include<bits/stdc++.h>
using namespace std;


int recursive(vector<int>v, int n, int count,int visited[],int ind){
	//cout << "hello world"<<endl;

	if(count >=n) {
		return 0;
	}
	
	int maximum = -1;
	//cout << "gwk" <<endl;

	for(int i=0; i<v.size(); i++){


			

			int cost = 0;
			int num = v[i];
			if(i<=0 && v.size()!=1) cost = v[i+1];
			else if(i>=v.size()-1 && v.size()!=1) cost = v[i-1];
			//else if(count==n-1) cost = v[i];
			else if(v.size()!=1) cost = (v[i+1])*(v[i-1]);
			else cost = num;
			//cout << i << " "<< v[i] << " "<<cost<<endl;
			
			
			v.erase(v.begin()+i);
				
			
			count++;
			
		

			maximum = max(maximum, recursive(v, n, count,visited,i)+cost);
			//cout << maximum << endl;

			
			v.insert(v.begin()+i,num);
				
			

			visited[i]=0;
			count--;

		

	}
	
	return maximum;
}

int main(){

	ios::sync_with_stdio(0), cin.tie(0);

   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
	int n;
	cin >>n;
	vector<int>v;
	for(int i=0; i<n; i++){
		int a; 
		cin >>a;
		v.push_back(a);
	}
	int count = 0;
	int visited[1000];
	for(int i=0; i<1000; i++) visited[i]=0;
	int res = recursive(v,n,count,visited,0);
	cout << res <<endl;
}