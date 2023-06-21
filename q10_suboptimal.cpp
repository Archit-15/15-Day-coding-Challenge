// 62. Unique Paths

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int up(int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    else if (i >= m || j >= n)
    {
        return 0;
    }
    else
    {
        return up(i + 1, j, m, n) + up(i, j + 1, m, n);
    }
}

int uniquePaths(int m, int n)
{
    int i = 0;
    int j = 0;
    int a1 =up(i, j, m, n);
    return a1;
}

int main()
{
    int ans = uniquePaths(3,7);
    cout<<ans;
    return 0;
}