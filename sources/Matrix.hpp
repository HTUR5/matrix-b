#include <iostream>
#include <ostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;
namespace zich {

    class Matrix {
        
        vector<double> matrix;
        int rows, cols;
    
    public:
        
        Matrix(const vector<double> &mat, int rows, int cols);

        Matrix operator-(Matrix const &other);

        Matrix operator-();

        Matrix& operator-=(Matrix const &other);

        Matrix operator+(Matrix const &other);

        Matrix operator+();

        Matrix& operator+=(Matrix const &other);

        Matrix operator*(double scalar);

        Matrix operator*(Matrix const &other);

        Matrix& operator*=(double scalar);
        
        Matrix& operator++();

        Matrix operator++(int);

        Matrix& operator--();

        Matrix operator--(int);

        bool operator<(Matrix  &other);

        bool operator<=(Matrix  &other);

        bool operator>(Matrix  &other);

        bool operator>=(Matrix  &other);

        bool operator!=(Matrix  &other);

        friend bool operator==(const Matrix  &mat1, const Matrix  &mat2);

        void print();

        Matrix operator*=(Matrix const &mat1);

        friend std::ostream &operator<<(std::ostream &out, Matrix const &mat);

        friend Matrix operator*(double const &n, Matrix const mat1);

        friend std::istream &operator>>(istream &input, Matrix &mat);
    };
}