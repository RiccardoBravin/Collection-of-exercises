#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>

class Matrix{
    public:
        Matrix(const int rows_, const int columns_);
        Matrix(const Matrix& mat);
        Matrix& operator=(const Matrix& mat);
        Matrix(Matrix&& mat);
        Matrix& operator=(Matrix&& mat);
        ~Matrix();
        void scale(const double x);
        void add(const double x);
        void add(const Matrix& m);
        void transpose();

        std::vector<double> row(const int i) const;
        std::vector<double> column(const int i) const;

        const int getRows() const {return rows;}
        const int getColumns() const {return col;}
        

        double* operator[](const int i);
        const double* operator[](const int i) const;
        Matrix operator+(const Matrix& b)const;
        Matrix operator*(const Matrix& b)const;

    private:
        int rows;
        int col;
        double** matrix;
};



std::ostream& operator<<(std::ostream& os, const Matrix& m);

#endif