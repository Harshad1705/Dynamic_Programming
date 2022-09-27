
#include <stdio.h>
#include <iostream>
// #include <climits>
using namespace std;

int minimum (int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

int solve(int arr[],int i,int j){
    
    if(i>=j){
        return 0;
    }
    int min = 10000000;
    for(int k=i ; k<=j-1 ; k++){
        int temp = solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        min = minimum(temp,min);
    }
    
    return min;
}

int main()
{
    int arr[] = {10,30,5,60};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int answer = solve(arr,1,size-1);
    
    cout<<answer;

    return 0;
}
