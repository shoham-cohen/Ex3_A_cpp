#include "Matrix.hpp"
using namespace std;

namespace zich

{

     Matrix::Matrix(vector<double> values, int rows, int colums)
    {
        if (rows < 1 || colums < 1)
        {
            throw runtime_error("cols and rows has to be positive");
        }
        vector<vector<double>> mat((size_t)rows, vector<double>((size_t)colums));
        this->rows = rows;
        this->colums = colums;
        this->mat = mat;
        size_t pos = 0;
        for (size_t row = 0; row < rows; row++)
        {
            for (size_t column = 0; column < colums; column++)
            {
                this->mat.at(row).at(column) = values.at(pos);
                pos++;
            }
        }
    }

    Matrix::Matrix(vector<vector<double>> mat, int rows, int colums)
    {
        if (colums < 1 || rows < 1)
        {
            throw runtime_error("cols and rows has to be positive");
        }
        this->colums = colums;
        this->rows = rows;
        this->mat = mat;
    }

    //plus operators
    Matrix operator + (const Matrix &first_mat, const Matrix &second_mat){
        if (first_mat.rows != second_mat.rows || first_mat.colums != second_mat.colums){
            throw runtime_error("the matrixs has to be in the same size");
        }
        vector<vector<double>> values((size_t)first_mat.rows, vector<double>((size_t)first_mat.colums));
        Matrix res(values, first_mat.rows, first_mat.colums);
        for (size_t row = 0; row < first_mat.rows; row++){
            for (size_t column = 0; column < first_mat.colums; column++){
                res.mat.at(row).at(column) = first_mat.mat.at(row).at(column) + second_mat.mat.at(row).at(column);
            }
        }
        return res;
    }

    Matrix operator + (const Matrix &mat){
        return mat;
    }

    void operator ++ (Matrix &mat){
        for (size_t row = 0; row < mat.rows; row++){
            for (size_t column = 0; column < mat.colums; column++){
                mat.mat.at(row).at(column)++;
            }
        }
    }

    void operator += (Matrix &mat, double num){
        for (size_t row = 0; row < mat.rows; row++){
            for (size_t column = 0; column < mat.colums; column++){
                mat.mat.at(row).at(column) += (num);
            }
        }
    }

    //minus operators
    Matrix operator - (const Matrix &first_mat, const Matrix &second_mat){
        if (first_mat.rows != second_mat.rows || first_mat.colums != second_mat.colums){
            throw runtime_error("the matrixs has to be in the same size");
        }
        vector<vector<double>> values((size_t)first_mat.rows, vector<double>((size_t)first_mat.colums));
        Matrix res(values, first_mat.rows, first_mat.colums);
        for (size_t row = 0; row < first_mat.rows; row++){
            for (size_t column = 0; column < first_mat.colums; column++){
                res.mat.at(row).at(column) = first_mat.mat.at(row).at(column) - second_mat.mat.at(row).at(column);
            }
        }
        return res;
    }

    Matrix operator - (const Matrix &mat){
        vector<vector<double>> values((size_t)mat.rows, vector<double>((size_t)mat.colums));
        Matrix res(values, mat.rows, mat.colums);
        for (size_t row = 0; row < mat.rows; row++){
            for (size_t column = 0; column < mat.colums; column++){
                res.mat.at(row).at(column) = -(mat.mat.at(row).at(column));
            }
        }
        return res;
    }

    void operator -= (Matrix &mat, double num){
        for (size_t row = 0; row < mat.rows; row++){
            for (size_t column = 0; column < mat.colums; column++){
                mat.mat.at(row).at(column) *= num;
            }
        }

    }
    
    void operator -- (Matrix &mat){
        for (size_t row = 0; row < mat.rows; row++){
            for (size_t column = 0; column < mat.colums; column++){
                mat.mat.at(row).at(column)--;
            }
        }
    }

    //multipication operators
    Matrix operator * (const Matrix &first_mat, const Matrix &second_mat){
        if (first_mat.colums != second_mat.rows){
            throw runtime_error("the rows of the first is not equal to the columns of the second");
        }
        vector<vector<double>> values((size_t)first_mat.rows, vector<double>((size_t)second_mat.colums));
        Matrix res(values, first_mat.rows, second_mat.colums);
        for (size_t row = 0; row < first_mat.rows; row++){
            for (size_t column = 0; column < second_mat.colums; column++){
                for (size_t temp = 0; temp < second_mat.rows; temp++){
                    res.mat.at(row).at(column) += first_mat.mat[row][temp] * second_mat.mat[temp][column];
                }
            }
        }
        return res;
    }


    Matrix operator * (double num, const Matrix &mat){
        vector<vector<double>> values((size_t)mat.rows, vector<double>((size_t)mat.colums));
        Matrix res(values, mat.rows, mat.colums);
        for (size_t row = 0; row < mat.rows; row++){
            for (size_t column = 0; column < mat.colums; column++){
                res.mat.at(row).at(column) *= num;
            }
        }
        return res;
    }


    void operator *= (Matrix &mat, double num){
        for (size_t row = 0; row < mat.rows; row++){
            for (size_t column = 0; column < mat.colums; column++){
                mat.mat.at(row).at(column) *= num;
            }
        }

    }

    //comparsion operators:
    bool operator > (const Matrix &first_mat, const Matrix &second_mat){
        if (first_mat.rows != second_mat.rows || first_mat.colums != second_mat.colums){
            throw runtime_error("the matrixs has to be in the same size");
        }
        for (size_t row = 0; row < first_mat.rows; row++){
            for (size_t column = 0; column < first_mat.colums; column++){
                if (first_mat.mat.at(row).at(column) <= second_mat.mat.at(row).at(column))
                    return false;
            }
        }
        return true;
    }

    bool operator < (const Matrix &first_mat, const Matrix &second_mat){
        if (first_mat.rows != second_mat.rows || first_mat.colums != second_mat.colums){
            throw runtime_error("the matrixs has to be in the same size");
        }
        for (size_t row = 0; row < first_mat.rows; row++){
            for (size_t column = 0; column < first_mat.colums; column++){
                if (first_mat.mat.at(row).at(column) >= second_mat.mat.at(row).at(column))
                    return false;
            }
        }
        return true;
    }

    bool operator >= (const Matrix &first_mat, const Matrix &second_mat){
        if (first_mat.rows != second_mat.rows || first_mat.colums != second_mat.colums){
            throw runtime_error("the matrixs has to be in the same size");
        }
        for (size_t row = 0; row < first_mat.rows; row++){
            for (size_t column = 0; column < first_mat.colums; column++){
                if (first_mat.mat.at(row).at(column) < second_mat.mat.at(row).at(column))
                    return false;
            }
        }
        return true;

    }

    bool operator <= (const Matrix &first_mat, const Matrix &second_mat){
        if (first_mat.rows != second_mat.rows || first_mat.colums != second_mat.colums){
            throw runtime_error("the matrixs has to be in the same size");
        }
        for (size_t row = 0; row < first_mat.rows; row++){
            for (size_t column = 0; column < first_mat.colums; column++){
                if (first_mat.mat.at(row).at(column) > second_mat.mat.at(row).at(column))
                    return false;
            }
        }
        return true;
    }

    bool operator == (const Matrix &first_mat, const Matrix &second_mat){
        if (first_mat.rows != second_mat.rows || first_mat.colums != second_mat.colums){
            throw runtime_error("the matrixs has to be in the same size");
        }
        for (size_t row = 0; row < first_mat.rows; row++){
            for (size_t column = 0; column < first_mat.colums; column++){
                if (first_mat.mat.at(row).at(column) != second_mat.mat.at(row).at(column))
                    return false;
            }
        }
        return true;
    }

    bool operator != (const Matrix &first_mat, const Matrix &second_mat){
        if (first_mat.rows != second_mat.rows || first_mat.colums != second_mat.colums){
            return true;
        }
        for (size_t row = 0; row < first_mat.rows; row++){
            for (size_t column = 0; column < first_mat.colums; column++){
                if (first_mat.mat.at(row).at(column) == second_mat.mat.at(row).at(column))
                    return false;
            }
        }
        return true;
    }
    

    //---------------- to do----------------------
    // input and output operators
    istream &operator >> (istream &in, const Matrix &mat)
    {
         return in;
    }
    ostream &operator << (ostream &o, const Matrix &mat)
    {
        return o;
    }

}