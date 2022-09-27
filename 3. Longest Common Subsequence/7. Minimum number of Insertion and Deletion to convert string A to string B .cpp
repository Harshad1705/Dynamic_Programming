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
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    
    return t[m][n];
}

int main()
{
    string X = "heap";
    string Y = "pea";
     
    int n = X.length();
    int m = Y.length();
    
    
    int ans = LCS(X,Y,n,m);
    
    int deletion = n-ans;
    int insertion = m-ans;
    
    cout<<"Insertion : "<<insertion<<endl;
    cout<<"Deletion : "<<deletion<<endl;
    

    return 0;
}
