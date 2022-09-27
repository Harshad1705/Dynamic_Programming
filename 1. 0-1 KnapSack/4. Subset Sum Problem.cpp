
#include <stdio.h>
#include <iostream>
using namespace std ;

bool SubsetSum(int arr[],int sum, int n){
    
    bool t[n+1][sum+1];
    
    
    for(int j=1;j<=sum;j++){
        t[0][j]=false;
    }
    for(int i=0;i<=n;i++){
        t[i][0]=true;
    }
    
    
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    
    if(t[n][sum]==true)
        return true;
    return false;
    
}

int main()
{
    int arr[]={1,6,11,5};
    int sum =11;
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int ans =SubsetSum(arr,sum,n);
    cout<<ans;

    return 0;
}
