
#include "Matrix.h"

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

Matrix::Matrix(const int rows_, const int columns_) : rows(rows_), col(columns_){
    matrix = new double*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new double[col];
        for(int j = 0; j < col; j++){
            matrix[i][j] = 0; 
        }
    }
}

Matrix::Matrix(const Matrix& mat) : rows(mat.rows), col(mat.col){
    matrix = new double*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new double[col];
        for(int j = 0; j < col; j++){
            matrix[i][j] = mat[i][j]; 
        }
    }
}
        
Matrix& Matrix::operator=(const Matrix& mat){
    if(this != &mat){
        for(int i = 0; i < rows; i++){
            delete[] this->matrix[i];
            this->matrix[i] = nullptr;   
        }
        delete[] matrix;
        this->col = mat.getColumns();
        this->rows = mat.getRows();
        matrix = new double*[rows];
        for(int i = 0; i < rows; i++){
            matrix[i] = new double[col];
            for(int j = 0; j < col; j++){
                matrix[i][j] = mat[i][j]; 
            }
        }
        
    }
    return *this;
}

Matrix::Matrix(Matrix&& mat){
    this->rows = mat.rows;
    this->col = mat.col;
    this->matrix = mat.matrix;
    mat.matrix = nullptr;
    mat.col = 0;
    mat.rows = 0;
}

Matrix& Matrix::operator=(Matrix&& mat){
    if(this != &mat){
        for(int i = 0; i < rows; i++){
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
        
        delete[] matrix;
        rows = mat.rows;
        col = mat.col;
        matrix = mat.matrix;
        mat.matrix = nullptr; 
        mat.col = 0;
        mat.rows = 0;
    }
    return *this;
}

Matrix::~Matrix(){
    for(int i = 0; i < rows; i++){
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    rows = 0;
    col = 0;
}

void Matrix::scale(const double x){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < col; j++){
            matrix[i][j] *= x; 
        }
    }
}

void Matrix::add(const double x){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < col; j++){
            matrix[i][j] += x; 
        }
    }
}

void Matrix::add(const Matrix& m){
    if(rows != m.rows || col != m.col)
        return;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < col; j++){
            matrix[i][j] += m[i][j]; 
        }
    }
    return;
}

void Matrix::transpose(){
    Matrix aux = Matrix(*this);
    for(int i = 0; i < rows; i++){
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    col = aux.rows;
    rows = aux.col;
    matrix = new double*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new double[col];
        for(int j = 0; j < col; j++){
            matrix[i][j] = aux.matrix[j][i]; 
        }
    }
}

double* Matrix::operator[](const int i){
    if(i > rows || i < 0)
        cout << "WARNING: Out of bounds reading\n";
    return matrix[i];
}


const double* Matrix::operator[](const int i) const{
    if(i > rows || i < 0)
        cout << "WARNING: Out of bounds reading\n";
    return matrix[i];
}

Matrix Matrix::operator+(const Matrix& b) const{
    if(rows != b.getRows() || col != b.getColumns())
        throw invalid_argument("ERROR: dimensions cannot be different");
    Matrix aux = Matrix(rows,col);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < col; j++){
            aux.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
        }
    }
    return aux;
}

Matrix Matrix::operator*(const Matrix& b) const{
    if(col != b.getRows())
        throw invalid_argument("ERROR: Columns of the fist argument must be equal to the rows of the second one");
    
    Matrix aux = Matrix(rows, b.getColumns());

    for(int r = 0; r < aux.rows; r++){
        for(int c = 0; c < aux.col; c++){
            double sum = 0;
            for(int i = 0; i < col; i++){
                sum += matrix[r][i]*b.matrix[i][c];
            }
            aux[r][c]=sum;
        }
    }
    return aux;
}


vector<double> Matrix::row(const int i) const{
    vector<double> vec{};
    if(i >= 0 && i <= rows)
        for(int j = 0; j < col; j++)
            vec.push_back(matrix[i][j]);
    return vec;
}


vector<double> Matrix::column(const int i)const {
    vector<double> vec{};
    if(i >= 0 && i < col)
        for(int j = 0; j < col; j++)
            vec.push_back(matrix[j][i]);
    return vec;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m){
    for(int i = 0; i < m.getRows(); i++){
        for(int j = 0; j < m.getColumns(); j++){
            os << m[i][j] << "\t"; 
        }
        os << endl;
    }
    return os;
}
