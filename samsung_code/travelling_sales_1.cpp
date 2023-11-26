#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;



int solve(int n, vector<vector<int>>&arr, int node, int ini_mask, int total_mask,int dp[5000][101]){
    if(ini_mask==total_mask){
        return arr[node][0];
    }
    if(dp[ini_mask][node]!=-1) dp[ini_mask][node];
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if((ini_mask & (1<<i))==0){
            int y=(ini_mask | (1<<i));
            int temp = arr[node][i]+solve(n, arr, i, y , total_mask,dp);
            ans=min(ans, temp);
        }
    }
    return dp[ini_mask][node]=ans;
}


int main() {

    ios::sync_with_stdio(0); cin.tie(0);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>arr;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                temp.push_back(x);
            } arr.push_back(temp);
        }
        // int x=pow(2, n);
        // int dp[x][n]={-1};
        int ini_mask=1;
        int total_mask=(1<<n)-1;
        int dp[5000][101];
        for(int i=0; i<total_mask; i++){
            for(int j=0; j<n+1; j++){
                dp[i][j]=-1;
            }
        }
        cout<<solve(n, arr, 0, ini_mask, total_mask, dp)<<endl;
    }
    return 0;
}