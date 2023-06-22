// 62. Unique Paths
// Time complexity -> O(m+n) as at max there will be m+n recursive calls , if there are more the 
// hash table will return the answer on its own. Space complexity -> O(m+n)

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int up(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    else if (i >= m || j >= n)
    {
        return 0;
    }
    else if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else
    {
        dp[i][j] = up(i + 1, j, m, n, dp) + up(i, j + 1, m, n, dp);
        return dp[i][j];
    }
}
int uniquePaths(int m, int n)
{
    int i = 0;
    int j = 0;
    vector<vector<int>> dp(m, vector<int>(n, -1)); // creates a 2d vector
    // with m rows and n elements eaech initialized to -1
    int ans = up(i, j, m, n, dp);
    return ans;
}

int main()
{
    int ans = uniquePaths(3, 7);
    cout << ans;
    return 0;
}