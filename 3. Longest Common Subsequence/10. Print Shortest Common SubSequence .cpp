
#include <string>
#include <bits/stdc++.h>
using namespace std;


int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

string LCS(string x, string y ,int m , int n)
{
    int t[m+1][n+1];
    string  s;
    
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
    
    int i=m;
    int j=n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }else{
            if(t[i-1][j]>t[i][j-1]){
                s.push_back(x[i-1]);
                i--;
            }else if (t[i][j-1]>t[i-1][j]){
                s.push_back(y[j-1]);
                j--;
            }
        }
    }
    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    
    return s;
}

int main()
{
    string X = "acbcf";
    string Y = "abcdaf";
     
    int n = X.length();
    int m = Y.length();
    
    
    string ans = LCS(X,Y,n,m);
    cout<<ans;

    return 0;
}
