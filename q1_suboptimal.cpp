// 73. Set Matrix Zeroes

#include <iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row[m] = {0};
        int col[n] = {0};
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j] = 0;
                }
            }
        }
}

int main() {
    vector<vector<int>> matrix{
        {0,1,1},
        {1,1,1},
        {1,1,1}
    };
    setZeroes(matrix);
    for(const auto& row : matrix){
        for(int element : row){
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}