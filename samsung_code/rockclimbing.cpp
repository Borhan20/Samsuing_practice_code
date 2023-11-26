#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[15][15];
int n,m;
int ans;

bool visited[15][15];

void solve(int x, int y, int diff){
    if(x<0 || y<0 || x>=n || y>=m){
        return;
    }
    if(arr[x][y]==3){
        ans=min(ans, diff);
        return;
    }
    
    visited[x][y]=true;
    
    int up=x-1;
    while(arr[up][y]==0 && up>=0){
        up--;
    }
    if(up>=0 && visited[up][y]==false){
        solve(up, y, max(diff, x-up));
    }
    
    int down=x+1;
    
    while(arr[down][y]==0 && down<n){
        down++;
    }
    if(down<n && visited[down][y]==false){
        solve(down, y, diff);
    }
    
    if(arr[x][y+1]!=0 && visited[x][y+1]==false && y+1<m){
        solve(x, y+1, diff);
    }
    if(arr[x][y-1]!=0 && !visited[x][y-1] && y-1>=0){
        solve(x, y-1, diff);
    }
    
    visited[x][y]=false;
    // return;
    
}


int main() {

	ios::sync_with_stdio(0), cin.tie(0);

   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            
        }
    }
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            visited[i][j]=false;
            
        }
    }
    ans=100;
    solve(n-1, 0, 0);
    cout<<ans<<endl;
    
    return 0;
}
