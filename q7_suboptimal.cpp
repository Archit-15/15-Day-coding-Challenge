// 74. Search a 2D Matrix

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i)
    {
        if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
        {
            int j = 0;
            while (j < n)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
                ++j;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix{
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60}
    };

    bool t = searchMatrix(matrix,61);
    cout<<t;
    return 0;
}