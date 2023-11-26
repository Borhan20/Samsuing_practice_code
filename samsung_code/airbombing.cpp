#include<bits/stdc++.h>
using namespace std;


int ans = -1;
vector<pair<int,int>>v;

int dp[100][100];

int recursive(int arr[100][100], int n,int x, int y,int b,int count){


    
    
    
    if(y<0)  return 0;
    if(y>=5) return 0;
    //if(b+1>=n) return;

    if(x<0) {
        //ans = max(ans,count);
        return 0;
    }

    if(dp[x][y]!=-1 && b) return dp[x][y];

    

    if(arr[x][y]==2 && b){
        //ans = max(ans,count);
        return 0;
    }



    if(arr[x][y]==1){
        int r=1+recursive(arr,n,x-1,y-1,b,count+1);
        int s=1+recursive(arr,n,x-1,y,b,count+1);
        int t=1+recursive(arr,n,x-1,y+1,b,count+1);
        dp[x][y] = max(r,max(s,t));

    }
    else if(arr[x][y]==0 || arr[x][y]==10){
        int r=recursive(arr,n,x-1,y-1,b,count);
        int s=recursive(arr,n,x-1,y,b,count);
        int t=recursive(arr,n,x-1,y+1,b,count);
        dp[x][y]=max(r,max(s,t));
    }


    else{

        if(b>0 && b <= 5){
            for(int j=0; j<5; j++){
                if(arr[x][j]==2) arr[x][j]=10;
            }
        }
        
        int r=recursive(arr,n,x-1,y-1,b+1,count);
        int s=recursive(arr,n,x-1,y,b+1,count);
        int t=recursive(arr,n,x-1,y+1,b+1,count);

        dp[x][y] = max(r,max(s,t));


        if(b>0 && b <= 5){
            for(int j=0; j<5; j++){
                if(arr[x][j]==10) arr[x][j]=2;
            }
        }

    }
        

        
        //cout << x <<" "<< y <<endl;
        //cout << ans <<endl;    

    return dp[x][y];


}

int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >>t;
    for(int r=1; r<=t; r++){
        int n;
        cin >> n;
        int arr[100][100];

        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                arr[i][j]=0;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                cin >> arr[i][j];
                //cout << arr[i][j]<<endl;
            }
        }
        for(int i=0; i<100; i++){
            for(int j=0; j<100;j++){
                dp[i][j]=-1;
            }
        }
        int res1 = recursive(arr,n,n-1,2,0,0);
        for(int i=0; i<100; i++){
            for(int j=0; j<100;j++){
                dp[i][j]=-1;
            }
        }
        int res2= recursive(arr,n,n-1,1,0,0);
        for(int i=0; i<100; i++){
            for(int j=0; j<100;j++){
                dp[i][j]=-1;
            }
        }
        int res3=recursive(arr,n,n-1,3,0,0);

        ans = max(res1,max(res2,res3));

        cout << "#" << r << " "<< ans <<endl;

        ans = 0;


    }
    

}