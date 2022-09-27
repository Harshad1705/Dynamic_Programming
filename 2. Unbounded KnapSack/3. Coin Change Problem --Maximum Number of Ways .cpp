
#include <stdio.h>
#include <iostream>
using namespace std ;

int CountOfSubsetSum(int arr[],int sum, int n){
    
    int t[n+1][sum+1];
    
    for(int i=0;i<=n;i++){
        t[i][0]=1;
    }
    
    for(int j=1;j<=sum;j++){
        t[0][j]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
}


int main(){
    int arr[]={1,2,3};
    int sum =5;
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    
    int ans =CountOfSubsetSum(arr,sum,n);
    cout<<ans;

    return 0;
}