
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int LCS(string x, string y ,int n , int m)
{
    if(n==0||m==0){
        return 0;
    }
    
    if(t[n][m]!=-1){
        return t[n][m];
    }
    
    if(x[n-1]==y[m-1]){
        return t[n][m]=1+LCS(x,y,n-1,m-1);
    }
    else{
        return t[n][m]=max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
    }
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
     
    int n = X.length();
    int m = Y.length();
    
    memset(t,-1,sizeof(t));
    
    int ans = LCS(X,Y,n,m);
    cout<<ans;

    return 0;
}
