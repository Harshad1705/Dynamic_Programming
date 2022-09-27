/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int LCS (string a , string b , int m , int n){
    int t[m+1][n+1];
    
    for(int i=0;i<m+1;i++){
        t[i][0] = 0;
    }
    for(int j=0;j<n+1;j++){
        t[0][j]=0;
    }
    
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(a[m-1]==b[n-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }else{
                t[i][j]= max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    
    return t[m][n];
}

int main()
{
    string a = "AXY";
    string b = "ADXCPY";
    
    int m = a.length();
    int n = b.length();
    
    int ans = LCS(a,b,m,n);
    
    if(ans==m){
        cout<<"True";
    }else{
        cout<<"False";
    }

    return 0;
}