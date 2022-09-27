
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std ;




int main()
{   
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int W=7;
    
    int n = sizeof(wt)/sizeof(wt[0]);
    
    int t[n+1][W+1];

    
    cout<<t[1][1];
    cout<<t[n][W];
    
    // Putting t[0][0] ,t[1][0] .. t[n+1][0] = 0
    for(int i =0;i<n+1;i++){
        t[i][0]=0;
    }
    
    // Putting t[0][0],t[0][1]....t[W+1][0]  = 0
    for(int j =0;j<W+1;j++){
        t[0][j]=0;
    }
    
    
    for(int i=1;i<n+1;i++){
        for(int j=1;i<W+1;j++){
            if(wt[i-1]<=j){
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]] , 						t[i-1][j]);
            }
            else{
                t[i][j]=t[n-1][j];
            }
            
        }
    }
    cout<<t[n][W];
    
    // cout<<sum;

    return 0;
}
