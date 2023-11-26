#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int check(int arr[100][100],int n, int m){
    int count =0;
    for(int i=0; i<n; i++){
        int flag =0;
        for(int j=0; j<m; j++){
            if(arr[i][j]==0) {
                flag++;
                
            }
            //cout << arr[i][j];
        }
        //cout << endl;
        if(flag==0) count++;
    }
    //cout << count <<endl;
    return count;
}

int recursive(int arr[100][100],int count, int k, int n, int m, int res){
    if(count>=k) return check(arr,n,m);
    
    for(int j=0; j<m; j++){
        
        for(int i=0; i<n; i++){
            if(arr[i][j]==0) arr[i][j]=1;
            else  arr[i][j]=0;
        }
        
        
        //res = check(arr,n,m);
         res = max(res, recursive(arr,count+1,k,n,m,res));
        //cout << res << " "<<j <<endl;
        
         
        
        
        for(int i=0; i<n; i++){
            if(arr[i][j]==0)arr[i][j]=1;
            else arr[i][j]=0;
        }
    }

    
    return res;
}


int main() {
    int n,m;
    int k;
    cin>> n >>m >>k;
    int arr[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    int res = recursive(arr, 0, k, n, m, -1);
    cout << res <<endl;
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

