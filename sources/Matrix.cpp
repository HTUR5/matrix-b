#include "Matrix.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <fstream>



using namespace zich;

namespace zich {

     Matrix::Matrix(const vector<double> &mat, int rows, int cols) {
        if(rows <= 0 || cols <= 0) {
            throw runtime_error("rows or cols should be positive");
        }
        if(mat.size() != rows * cols) {
            throw runtime_error("rows * cols should be like the mat size");
        }
        this->rows = rows;
        this->cols = cols;
        this->matrix = mat;
    }

    Matrix Matrix::operator-(Matrix const &other) {
        if(this->rows != other.rows || this->cols != other.cols) {
            throw runtime_error("matrix should have the same size");
        }
        vector<double> ans;
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            ans.push_back(this->matrix.at(i) - other.matrix.at(i));
        }
        Matrix mat_ans{ans, this->rows, this->cols};
        return mat_ans;
    }

    Matrix Matrix::operator-() {
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            this->matrix.at(i) *= -1;
        }
        return *this;
    }

    Matrix& Matrix::operator-=(Matrix const &other) {
        if(this->rows != other.rows || this->cols != other.cols) {
            throw runtime_error("matrix shuld have the same size");
        }
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            this->matrix.at(i) -= other.matrix.at(i);
        }
        return *this;    
    }

    Matrix Matrix::operator+(Matrix const &other) {
        if(this->rows != other.rows || this->cols != other.cols) {
            throw runtime_error("matrix shuld have the same size");
        }
        vector<double> ans;
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            ans.push_back(this->matrix.at(i) + other.matrix.at(i));
        }
        Matrix mat_ans{ans, this->rows, this->cols};
        return mat_ans;
    }

    Matrix Matrix::operator+() {
        return *this;
    }

    Matrix& Matrix::operator+=(Matrix const &other) {
        if(this->rows != other.rows || this->cols != other.cols) {
            throw runtime_error("matrix should have the same size");
        }
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            this->matrix.at(i) += other.matrix.at(i);
        }
        return *this; 
    }

    Matrix Matrix::operator*(double scalar) {
        vector<double> ans;
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            ans.push_back(this->matrix.at(i)*scalar);
        }
        Matrix mat_ans{ans, this->rows, this->cols};
        return mat_ans;
    }

    Matrix Matrix::operator*(Matrix const &other) {
        if(this->cols != other.rows) {
            throw runtime_error("matrix should have the same size");
        }
        vector<double> ans;
        for (unsigned long i = 0; i <this->rows; i++) {
            for (unsigned long j = 0; j < other.cols; j++) {
                double sum = 0;
                for (unsigned long c = 0; c < other.rows; c++) {
                sum += this->matrix.at(i*(unsigned long)(this->cols)+c) * other.matrix.at(j+c*(unsigned long)(other.cols));
                }
                ans.push_back(sum);
            }
        }
        Matrix mat_ans{ans, this->rows, other.cols};
        return mat_ans;
    }

    Matrix& Matrix::operator*=(double scalar) {
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            this->matrix.at(i) *= scalar;
        }
        return *this; 
    }

    Matrix& Matrix::operator--() {
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            this->matrix.at(i)--;
        }
        return *this;
    }

    Matrix Matrix::operator--(int) {
        Matrix ans = *this;
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            this->matrix.at(i)--;
        }
        return ans;   
    }

    Matrix& Matrix::operator++() {
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            this->matrix.at(i)++;
        }
        return *this;  
    }

    Matrix Matrix::operator++(int) {
        Matrix ans = *this;
        int size = this->rows*this->cols;
        for (unsigned long i = 0; i < size; ++i) {
            this->matrix.at(i)++;
        }
        return ans;     
    }
    
    bool operator==(const Matrix  &mat1, const Matrix  &mat2) {
        if(mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
            throw runtime_error("matrix should have the same size");
        }
        for(unsigned long i = 0; i < mat1.cols*mat1.rows; i++) {
            if(mat1.matrix.at(i) != mat2.matrix.at(i)) {
                return false;
            }
        }
        return true;
    }

    bool Matrix::operator!=(Matrix &other) {
        if(this->rows != other.rows || this->cols != other.cols) {
            throw runtime_error("matrix should have the same size");
        }
        for(int i = 0; i < other.cols*other.rows; i++) {
            if(this->matrix.at((unsigned long)i) != other.matrix.at((unsigned long)i)) {
                return true;
            }
        }
        return false;
    }
    
    bool Matrix::operator<( Matrix &other) {
        if(this->rows != other.rows || this->cols != other.cols) {
            throw runtime_error("matrix should have the same size");
        }
        double sumOfThis = 0;
        for(int i = 0; i < this->rows*this->cols; i++) {
            sumOfThis+=this->matrix.at((unsigned long)i);
        }
        double sumOfOther = 0;
        for(int i = 0; i < other.rows*other.cols; i++) {
            sumOfOther+=other.matrix.at((unsigned long)i);
        }
        return sumOfThis < sumOfOther;
    }

    bool Matrix::operator<=( Matrix &other) {
        if(this->rows != other.rows || this->cols != other.cols) {
            throw runtime_error("matrix should have the same size");
        }
        double sumOfThis = 0;
        for(int i = 0; i < this->rows*this->cols; i++) {
            sumOfThis+=this->matrix.at((unsigned long)i);
        }
        double sumOfOther = 0;
        for(int i = 0; i < other.rows*other.cols; i++) {
            sumOfOther+=other.matrix.at((unsigned long)i);
        }
        return sumOfThis <= sumOfOther;
    }
    
    bool Matrix::operator>( Matrix &other) {
        if(this->rows != other.rows || this->cols != other.cols) {
            throw runtime_error("matrix should have the same size");
        }
        double sumOfThis = 0;
        for(int i = 0; i < this->rows*this->cols; i++) {
            sumOfThis+=this->matrix.at((unsigned long)i);
        }
        double sumOfOther = 0;
        for(int i = 0; i < other.rows*other.cols; i++) {
            sumOfOther+=other.matrix.at((unsigned long)i);
        }
        return sumOfThis > sumOfOther;
    }
    
    bool Matrix::operator>=( Matrix &other) {
        if(this->rows != other.rows || this->cols != other.cols) {
            throw runtime_error("matrix should have the same size");
        }
        double sumOfThis = 0;
        for(int i = 0; i < this->rows*this->cols; i++) {
            sumOfThis+=this->matrix.at((unsigned long)i);
        }
        double sumOfOther = 0;
        for(int i = 0; i < other.rows*other.cols; i++) {
            sumOfOther+=other.matrix.at((unsigned long)i);
        }
        return sumOfThis >= sumOfOther;
    }

    std::ostream &operator<<(std::ostream &out, Matrix const &mat) {
        for (unsigned long i = 0; i < mat.rows; i++) {
            out << '[';
            for (unsigned long j = 0; j < mat.cols; j++) {
                if(j==mat.cols-1){
                    out << mat.matrix.at((i * (unsigned long)(mat.cols) + j)) << ']';
                }
                else{
                    out << mat.matrix.at((i * (unsigned long)(mat.cols)) + j) << ' ';
                }
            }
            if(i!=mat.rows-1){
                out << '\n';
            }
        }
        return out ;
    }

    Matrix Matrix::operator*=(const Matrix &mat1) {
        if (this->cols != mat1.rows) {
            throw runtime_error("col1 must be equal to row2");
        }
        *this = (*this) * mat1;
        return *this;

    }
    
    Matrix operator*(double const &n, Matrix mat1) {
            vector<double> matrix_ans;
            for (std::vector<int>::size_type i = 0; i < mat1.rows*mat1.cols; i++) {
                matrix_ans.push_back(n*mat1.matrix.at(i));
            }
            Matrix ans = Matrix(matrix_ans, mat1.rows, mat1.cols);
            return ans;
    }
    
    std::istream &operator>>(istream &input, Matrix &mat) {
        char ch = 0;
        string str;
        while (ch != '\n') {
            ch = input.get();
            str += ch;
        }
        str.pop_back();
        vector<double> vec;
        string num;
        bool startRow = false;
        bool endRow = false;
        bool firstCountCols = true;
        int countCols = 0;
        int rows = 0;
        int cols = 0;
        for (std::string::size_type i = 0; i < str.length(); i++) {
            if(str.at(i) == '[') {
                if(i > 0) {
                    if(!endRow) {throw invalid_argument("invalid string");}
                    endRow = false;
                }
                startRow = true;
                countCols = 0;
            }
            else if(isdigit(str.at(i)) != 0 && startRow) {
                num += str.at(i);
            }
            else if(str.at(i) == ' ' && startRow  && isdigit(str.at(i+1)) != 0 && isdigit(str.at(i-1)) != 0) {
                if(firstCountCols) {cols++;}
                countCols++;
                vec.push_back(stod(num));
                num.clear();
            }
            else if(str.at(i) == ']') {
                if(firstCountCols) {cols++;}
                countCols++;
                vec.push_back(stod(num));
                num.clear();
                if(cols != countCols) {throw invalid_argument("invalid string");}
                firstCountCols = false;
                startRow = false; 
                endRow = true;
                rows++;
                if(i < str.length()-1) {
                if(str.at(i+1) != ',' || str.at(i+2) != ' ') {throw invalid_argument("invalid string");}
                i+=2;
                }
            }
            else {
                throw invalid_argument("invalid string");
            }
            
        }
        mat.matrix = vec;
        mat.rows = rows;
        mat.cols = cols;
        return input;  
    }
}

//  int main() {
//     vector<double> vec = {0,0};
//     Matrix mat1 = Matrix(vec,1,2);
//     istringstream is7{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
//     is7 >> mat1;
//     std::cout << mat1 << endl;
//     return 0;
//     }


