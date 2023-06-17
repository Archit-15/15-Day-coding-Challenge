// 74. Search a 2D Matrix


#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = (m * n) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (matrix[mid / n][mid % n] == target)
        {
            return true;
        }
        else if (matrix[mid / n][mid % n] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix{
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    bool t = searchMatrix(matrix, 61);
    cout << t;
    return 0;
}