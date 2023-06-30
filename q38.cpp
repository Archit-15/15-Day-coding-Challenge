// Fractional Knapsack
#include<isotream>
#include<bits/stdc++.h>

struct Item{
    int value;
    int weight;
};

bool comp(Item A, Item B){
    double r1 = A.value / A.weight;
    double r2 = B.value / B.weight;
    return  r1 > r2;
}

double knapsack(Item arr[],int n,int W){
    sort(arr,arr+n,comp);
    int currweight = 0;
    double finalvalue = 0;
    for(int i=0;i<n:++i){
        if(currweight + arr[i].weight <= W){
            currweight = currweight + arr[i].weight;
            finalvalue = finalvalue + arr[i].value;
        }
        else{
            int remain = W - currweight;
            finalvalue = arr[i].value * double(remain)/double(arr[i].weight);
            break;
        }
    }
    return finalvalue;
}

