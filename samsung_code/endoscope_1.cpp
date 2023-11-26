// #include "dbg.h"
#include<bits/stdc++.h>
using namespace std;





int connection[7][4]={
  {1,1,1,1},
  {0,0,1,1},
  {1,1,0,0},
  {0,1,1,0},
  {0,1,0,1},
  {1,0,0,1},
  {1,0,1,0},
};
int dx[4] ={0,0,-1,1};
int dy[4] ={-1,1,0,0,};
int visited[100][100];

int bfs(int pipe[100][100],int n, int m, int x, int y,int l, int count){

  for(int i=0; i<100; i++){
    for(int j=0; j<100; j++){
      visited[i][j]=0;
    }
  }
  queue<pair<int,int>> q;
  q.push(make_pair(x,y));
  visited[x][y]=1;


  int dis[100][100];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      dis[i][j]=0;
    }
  }
  while(!q.empty()){
    

    
    pair<int,int>p;
    p = q.front();
    int u = p.first;
    int v = p.second;
    if(dis[u][v] >= l-1) break;
    //cout << u << " "<<v<<endl;
    q.pop();
    
    for(int i=0; i<4; i++){

      int s = u+dx[i];
      int t = v+dy[i];
      //cout << u<< " "<<v<< " "<< s<< " "<< t <<endl;
      if(s>=0 && t>=0 && s<n && t<m ){
       
        if(visited[s][t]==0 && pipe[s][t]!=0){
          

          //cout << i<< " "<< s << " "<< t <<" "<< pipe[s][t] <<endl;

          if( i==0 && connection[pipe[u][v]-1][i]==connection[pipe[s][t]-1][i+1] && connection[pipe[u][v]-1][i]==1){
            q.push(make_pair(s,t));
            if(abs(s-x)+abs(t-y)+1 <=l)count++;
            visited[s][t]=1;
            dis[s][t]=dis[u][v]+1;
          }
          else if(i==1 && connection[pipe[u][v]-1][i]==connection[pipe[s][t]-1][i-1] && connection[pipe[u][v]-1][i]==1){
            q.push(make_pair(s,t));
            if(abs(s-x)+abs(t-y)+1 <=l)count++;
            visited[s][t]=1;
            dis[s][t]=dis[u][v]+1;
          }
          else if(i==2 && connection[pipe[u][v]-1][i]==connection[pipe[s][t]-1][i+1] && connection[pipe[u][v]-1][i]==1){
            q.push(make_pair(s,t));
            if(abs(s-x)+abs(t-y)+1 <=l)count++;
            visited[s][t]=1;
            dis[s][t]=dis[u][v]+1;
         }
          else if(i==3 && connection[pipe[u][v]-1][i]==connection[pipe[s][t]-1][i-1] && connection[pipe[u][v]-1][i]==1){
            //cout << "fuck"<<endl;
            q.push(make_pair(s,t));
            if(abs(s-x)+abs(t-y)+1 <=l)count++;
            visited[s][t]=1;
            dis[s][t]=dis[u][v]+1;
          }

        }
        
          
      }
    }

  }
  return count;

}


int main(){
  ios::sync_with_stdio(0), cin.tie(0);

   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
  
  int t;
  cin >>t;
  while(t--){
    int n,m,x,y,l;
    cin >>n >>m >>x >>y >> l;
    int pipe[100][100];
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin>> pipe[i][j];
      }
    }
    int res = bfs(pipe,n,m,x,y,l,1);
    cout << res <<endl;
    //cout << endl;
  }
}
