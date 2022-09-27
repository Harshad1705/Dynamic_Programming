
#include <string>
#include <bits/stdc++.h>
using namespace std;


int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int solve ( int arr[],int i,int j){
    int ans = 0;
    if(i>j){
        return 0 ;
    }
    for(int k=i;k<j;k++){
        int temp = solve(arr,i,k)+solve(arr,k+1,j);
        ans = max(ans,temp);  // function depend on question
    }
    return ans;
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int i=0;
    int j=4;
    
    cout<<solve(arr,i,j);
    

    return 0;
}
