//50. Pow(x, n)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


double myPow(double x, int n)
{
    long int n1 = abs(n);
    double product = 1.0;
    while (n1 > 0)
    {
        if (n1 % 2 != 0)
        {
            product = product * x;
            n1 = n1 - 1;
        }
        else
        {
            x = x * x;
            n1 = n1 / 2;
        }
    }
    if (n < 0)
    {
        return (double)(1.0) / (double)(product);
    }
    return product;
}

int main()
{
    int x = 2;
    int n = 10;
    double ans = myPow(2,10);
    cout<<ans;
}
