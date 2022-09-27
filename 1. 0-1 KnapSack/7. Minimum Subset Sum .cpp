
#include <stdio.h>
#include <iostream>
#include <vector> 
using namespace std ;

int Min(int a,int b){
    if(a>b)
        return b;
    return a;
}

vector<int> SubsetSum(int arr[],int range, int n){
    
    bool t[n+1][range+1];

    for(int j=0;j<=range;j++){
        t[0][j]=false;
    }
    for(int i=0;i<=n;i++){
        t[i][0]=true;
    }
    
   
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=range;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    
    
    // for(int i=0;i<=range;i++){
    //     cout<<t[n][i];
    // }
    // cout<<"\n";
    
    
    vector<int> v;
    for(int i=0;i<range/2+1;i++){
        if(t[n][i]==1){
            v.push_back(i);
        }
    }
    
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<"\n";
    // }
    
    
    return v;
}


int MinimunSubsetSum(int arr[],int range,int n){
    
   vector<int> v = SubsetSum(arr,range,n) ;

   
   int min=range;
   
   for(int i=0;i<v.size();i++){
       min=Min(min,range-2*v[i]);
   }
   
   return min;
}





int main(){
    
    int arr[]={1,6,11,5};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int range=0;
    
    for(int i=0;i<n;i++){
        range=range+arr[i];
    }
    
 

    int ans =MinimunSubsetSum(arr,range,n);
    cout<<ans;

    return 0;
}
