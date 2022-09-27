
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

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
    
    if(x[n-1]==y[m-1]){
        return 1+LCS(x,y,n-1,m-1);
    }
    else{
        return max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
    }
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
     
    int n = X.length();
    int m = Y.length();
    
    int ans = LCS(X,Y,n,m);
    cout<<ans;

    return 0;
}
