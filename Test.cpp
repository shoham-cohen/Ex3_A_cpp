#include "doctest.h"
#include "Matrix.hpp"
using namespace std;
using namespace zich;

TEST_CASE("Good Input"){
    vector<double> first = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<vector<double>> second = {{2, 4, 6, 8, 10}, {1, 3, 5, 7, 9}};
    vector <double> negative_first = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    vector<vector<double>> negative_second = {{-2, -4, -6, -8, -10}, {-1, -3, -5, -7, -9}};
    vector<double> zero = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<double> ones = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<vector<double>> res = {{4, 10, 16, 22, 28}, {10, 24, 38, 52, 66}, {16, 38, 60, 82, 104}, {22, 52, 82, 112, 142}, {28, 66, 104, 142, 180}};
    Matrix first_mat(first, 5, 2); //{{1, 2, 3, 4, 5} {6, 7, 8, 9, 10}}
    Matrix second_mat(second, 2, 5);
    Matrix neg_first_mat(negative_first, 5, 2);
    Matrix neg_second_mat(negative_second, 2, 5);
    Matrix zero_mat(zero, 5, 2);
    Matrix res_mat(res, 5, 5);
    
    
    CHECK(first_mat > neg_first_mat);
    CHECK(neg_second_mat < second_mat);
    CHECK((first_mat + neg_first_mat) == zero_mat);
    CHECK(first_mat != second_mat);
    CHECK((first_mat * second_mat) == res_mat);
    CHECK((-first_mat) == neg_first_mat);
    CHECK((-second_mat) == neg_second_mat);
    CHECK((+first_mat) == first_mat);
}
TEST_CASE("Bad input"){
    bool stam;
    vector<double> first = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<vector<double>> second = {{2, 4, 6, 8, 10}, {1, 3, 5, 7, 9}};
    vector<double> zero = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix first_mat(first, 2, 5); 
    Matrix second_mat(second, 1, 10);
    Matrix zero_mat(zero, 2, 5);
    CHECK_THROWS(Matrix invallid(first, 0, 0));
    CHECK_THROWS(Matrix invallid(second, -12, 2));
    CHECK_THROWS(Matrix invallid(zero, 1, -1));
    CHECK_THROWS(Matrix invallid(first, -11, -13));
    CHECK_THROWS(first_mat + second_mat);
    CHECK_THROWS(first_mat * second_mat);
    CHECK_THROWS(zero_mat - second_mat);
    CHECK_THROWS(stam = (first_mat == second_mat));
    CHECK_THROWS(stam = (second_mat == zero_mat));
    CHECK_THROWS(stam = (first_mat >= second_mat));
    CHECK_THROWS(stam = (zero_mat <= second_mat));
    CHECK_THROWS(stam = (second_mat > first_mat));
}


