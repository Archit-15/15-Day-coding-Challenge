//Minimize the maximum difference between towers

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int minimize_difference(int arr[],int n,int k){
    sort(arr,arr+n);
    int ans = arr[n-1] - arr[0];        //Maximum possible difference, we have to minimize this
    int tempmin = arr[0];       //Without any modification this is the smallest value
    int tempmax = arr[n-1];     //Without any modification this is the highest value

    for(int i=1;i<n;++i){
        if(arr[i]-k<0){
            continue;
        }

        //Subtracting k from every element of array from n to i
        tempmax = max(arr[i-1]+k,arr[n-1]-k);
        
        //Adding k to every element of array till i-1
        tempmin = min(arr[0]+k,arr[i]-k);

        ans = min(ans,tempmax - tempmin);
    }
    return ans;
}

int main()
{
    int a[] = {11,14,5,18,16,7};   
    int N = sizeof(a)/sizeof(a[0]);
    cout<<"Difference between 2 towers is "<<minimize_difference(a,N,3);
    return 0;
}

// VVVVVI -> SINCE IT IS SORTED CONSECTUIVE ELEMENTS HAVE THE LOWEST DIFFERNECE BETWEEN THEM AND WE HAVE 
// OBSERVED THAT THE LOWEST NUMBER IS INCREASED AND THE HIGHEST NUMBER IS DICREASED. SO WE WILL TRY TO 
// MAKE THE 1ST ELEMENT(SMALLER) OF PAIR AS THE LARGEST BY ADDING K TO IT AND MAKE 2ND ELEMENT THE SMALLEST
// BY DECREASEING K FROM IT. 