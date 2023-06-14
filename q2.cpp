// 121. Best Time to Buy and Sell Stock

#include<iostream>
#include<vector>
using namespace std;

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

int BuyAndSell(vector<int> &stock){
    int maxProfit = 0;
    int mini = stock[0];
    int cost;
    for(int i=0;i<stock.size();++i){
        cost = stock[i] - mini;
        maxProfit = max(cost,maxProfit);
        mini = min(mini,stock[i]);
    }
    return maxProfit;
}

int main()
{
    vector<int> stock = {7,1,5,3,6,4};
    int ans = BuyAndSell(stock);
    cout<<ans;
    return 0;
}