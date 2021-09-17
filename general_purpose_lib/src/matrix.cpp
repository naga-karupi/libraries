/*element

*/
#include<stdio.h>
#include<stdlib.h>

#include<vector>
using namespace std;
namespace matrix{
    vector<vector<int>> matrix_C{
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
}

vector<vector<int>>matrix_sum(int*, int*);



vector<vector<int>> matrix_sum(vector<vector<int> >&matrix_A, vector<vector<int>>&matrix_B, int element){
    for (int i = 0;i < element; i++){
        for(int j = 0; j < element; i++){
            matrix::matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
    return matrix::matrix_C;
}


vector<vector<int>>&matrix_product(vector<vector<int> >&matrix_A, vector<vector<int>>&matrix_B, int element){

    
    for(int i = 0; i < element; i++){
        for(int j = 0; j < element; j++){
            for(int k = 0; k < element; k++){
                matrix::matrix_C[i][j] += matrix_A[k][j]*matrix_B[i][k];
            }
        }
    }
    return matrix::matrix_C;
}
