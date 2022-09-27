
#include <stdio.h>
#include <iostream>
using namespace std ;

int unboundedKnapSaack(int arr[],int val[],int n, int W){
    
   int t[n+1][W+1];
    
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    
    for(int j=1;j<=W;j++){
        t[0][j]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(arr[i-1]<=j){
                t[i][j]=max(val[n-1]+t[i][j-arr[i-1]] , t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    
    return t[n][W];
}


int main(){
    int arr[]={1,3,4,5};
    int val[]={1,4,5,7};
    int W =7;
    
    int n = sizeof(arr)/sizeof(arr[0]);

    
    int ans =unboundedKnapSaack(arr,val,n,W);
    cout<<ans;

    return 0;
}
