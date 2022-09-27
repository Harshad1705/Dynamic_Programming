
#include <stdio.h>
#include <iostream>
using namespace std ;

int RodCutting(int len[],int price[],int n, int N){
    
   int t[n+1][N+1];
    
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    
    for(int j=1;j<=N;j++){
        t[0][j]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=N;j++){
            if(len[i-1]<=j){
                t[i][j]=max(price[n-1]+t[i][j-len[i-1]] , t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    
    return t[n][N];
}


int main(){
    int len[]={1,2,3,4,5,6,7,8};
    int price[]={1,   5 ,  8 ,  9  ,10 , 17,  17 , 20};
    int N =8;
    
    int n = sizeof(len)/sizeof(len[0]);

    
    int ans =RodCutting(len,price,n,N);
    cout<<ans;

    return 0;
}
