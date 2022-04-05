#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
#include <iostream>
using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        int rows, colums;
        vector<vector<double>> mat;

    public:
        Matrix(vector<double> one_d_mat, int rows, int colums);
        Matrix(vector<vector<double>> mat, int rows, int colums);
        //plus operators
        friend Matrix operator + (const Matrix &first_mat, const Matrix &second_mat);
        friend Matrix operator + (const Matrix &first_mat);
        friend void operator ++ (Matrix &mat);
        friend void operator += (Matrix &mat, double num);

        //minus operators
        friend Matrix operator - (const Matrix &first_mat, const Matrix &second_mat);
        friend Matrix operator - (const Matrix &mat);
        friend void operator -- (Matrix &mat);
        friend void operator -= (Matrix &mat, double num);

        //multipication operators
        friend Matrix operator * (const Matrix &first_mat, const Matrix &second_mat);
        friend Matrix operator * (double num, const Matrix &first_mat);
        friend void operator *= (Matrix &mat, double num);
        
        //comparison operators
        friend bool operator > (const Matrix &first_mat, const Matrix &second_mat);
        friend bool operator < (const Matrix &first_mat, const Matrix &second_mat);
        friend bool operator >= (const Matrix &first_mat, const Matrix &second_mat);
        friend bool operator <= (const Matrix &first_mat, const Matrix &second_mat);
        friend bool operator == (const Matrix &first_mat, const Matrix &second_mat);
        friend bool operator != (const Matrix &first_mat, const Matrix &second_mat);
        // cout and cin operatos:
        friend istream &operator >> (istream &in, const Matrix &m);
        friend ostream &operator << (ostream &out, const Matrix &m);
    };
}
#endif