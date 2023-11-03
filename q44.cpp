// minimum platforms

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a < b;
}

int MinPlat(int arr[],int dep[],int n){
    sort(arr,arr+n,comp);
    sort(dep,dep+n,comp);
    int i = 0 , j = 0;
    int count = 0 , ans = 0;
    while(i<n){
        if(arr[i] <= dep[j]){
            count++;
            i++;
            ans = max(count,ans);
        }
        else{
            count--;
            j++;
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int ans = MinPlat(arr,dep,n);
    cout<<ans;
    return 0;
}