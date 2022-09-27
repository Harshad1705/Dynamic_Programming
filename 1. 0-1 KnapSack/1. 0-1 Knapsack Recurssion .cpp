
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std ;


int knapSack( int wt[], int val[],int W, int n)
{
 
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
   
    if (wt[n - 1] > W)
        return knapSack( wt, val, W,n - 1);
    else
        return max(val[n - 1]+ knapSack(wt, val,W - wt[n - 1], n - 1),knapSack(wt, val,W,  n - 1));
}

int main()
{   
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int W=7;
    
    int n = sizeof(wt)/sizeof(wt[0]);
    
    int sum =knapSack(wt,val,W,n);
    
    cout<<sum;

    return 0;
}
