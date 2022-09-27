
// #include <stdio.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;


int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int LCS(string x, string y ,int m , int n)
{
    int t[m+1][n+1];
    int result =0;
    
    for(int i=0;i<m+1;i++){
        t[i][0]=0;
    }
    
    for(int j=0;j<n+1;j++){
        t[0][j]=0;
    }
    
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                t[i][j] = 1+t[i-1][j-1];
                result = max(result,t[i][j]);
            }
            else{
                t[i][j] = 0;
            }
        }
    }
    
    return result;
}

int main()
{
    string X = "abcde";
    string Y = "abfce";
     
    int n = X.length();
    int m = Y.length();
    
    
    int ans = LCS(X,Y,n,m);
    cout<<ans;

    return 0;
}
