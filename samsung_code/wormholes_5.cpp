#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios::sync_with_stdio(0), cin.tie(0);

   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sx,sy,dx,dy;
        cin >> sx >> sy >> dx >> dy;
        vector<vector<int>>v;
        vector<int>r;
        r.push_back(sx);
        r.push_back(sy);
        r.push_back(sx);
        r.push_back(sy);
        r.push_back(0);
        
        v.push_back(r);
        r.clear();
        
        for(int i=0; i<n; i++){
            int a,b,c,d,e;
            cin >> a >> b >>c >> d >> e;
            vector<int>in;
            in.push_back(a);
            in.push_back(b);
            in.push_back(c);
            in.push_back(d);
            in.push_back(e);
            v.push_back(in);
        }
        r.push_back(dx);
        r.push_back(dy);
        r.push_back(dx);
        r.push_back(dy);
        r.push_back(0);
        v.push_back(r);
        r.clear();
        int inf = 1000000;
        int mat[100][100];
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
            
                mat[i][j]=inf;
                
            }
        }
        //cout << v.size()<<endl;
        for(int i=0; i<=n+1; i++){
            for(int j=0; j<=n+1; j++){
                
               
                    int p= v[i][4]+abs(v[i][2]-v[j][0])+abs(v[i][3]-v[j][1]);
                    int q= v[i][4]+abs(v[i][2]-v[j][2])+abs(v[i][3]-v[j][3]);
                    int r= v[i][4]+abs(v[i][0]-v[j][0])+abs(v[i][1]-v[j][1]);
                    int s= v[i][4]+abs(v[i][0]-v[j][2])+abs(v[i][0]-v[j][3]);
                    mat[i][j] = min(p,min(q,min(r,s)));
               
            }
        }
        
        
        for(int k=0; k<=n+1; k++){
            for(int i=0; i<=n+1; i++){
                for(int j=0; j<=n+1; j++){
                    mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
        
        cout << mat[0][n+1]<<endl;
        v.clear();
    }
    return 0;
}
