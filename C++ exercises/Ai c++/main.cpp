#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char const *argv[])
{
    std::cout << setprecision(3) << fixed;
    Matrix mat1 = Matrix(10, 10);
    mat1.add(1);
    mat1.scale(-2);
    mat1[2][4] = 10;
    cout << mat1 << endl;
    
    Matrix mat2 = Matrix(10, 10);
    mat2.add(1);
    mat1.add(mat2);
    mat1 = mat2 + mat1;
    
    cout << mat1 << endl;

    Matrix identity = Matrix(10,5);
    for(int i = 0; i < identity.getColumns() && i < identity.getRows(); i++){
        identity[i][i] = 2;
    }
    mat2 = mat2 * identity;
    cout << mat2 << endl;
    mat2.transpose();
    cout << mat2 << endl;

    cout << mat1.column(4)[2] << endl;
    cout << mat1.row(2)[4] << endl;

    return 0;
}

//4F