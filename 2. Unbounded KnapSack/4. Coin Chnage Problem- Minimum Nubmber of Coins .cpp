
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int Coin_Change(int coin[] ,  int n , int sum){
    
    int t[n+1][sum+1];
    
     for(int j=0;j<sum+1;j++){
        t[0][j]=INT_MAX-1;
    }
    
    for(int i=1;i<n+1;i++){
        t[i][0]=0;
    }
    
    for(int i=2;i<=sum;i++){
        if( i % coin[0] == 0)
            t[1][i]=i%coin[0];
        else
            t[1][i]=INT_MAX-1;
    }
    
    
    
    
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            
            if(coin[i-1]<=j)
            {
                t[i][j]  = min( t[i][j-coin[i-1]] +1 , t[i-1][j]  );
            }
            else{
                t[i][j]= t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
    
}

int main()
{
    int coin[]={1,2,3};
    int sum = 5;
    
    int n = sizeof(coin)/sizeof(coin[0]);
    
    
    int ans = Coin_Change(coin,n,sum);
    
    cout<<ans;

    return 0;
}