#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size()-1;++i){
        for(int j=i+1;j<matrix.size();++j){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //reverse
    for(int i=0;i<matrix.size();++i){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix{
        {10,23,24,14,15},
        {11,13,29,1,6},
        {4,2,7,8,9},
        {33,36,38,31,30},
        {41,45,54,46,48}
    };
    rotate(matrix);
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<matrix[0].size();++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}