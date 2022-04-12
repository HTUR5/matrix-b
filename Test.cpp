#include "doctest.h"
#include "Matrix.hpp"

using namespace zich;
TEST_CASE ("CHEK_THROWS WHEN USE OPERTORS ON NOT APPROPIATE MATRICES") {
    vector<double> vector1 = {1,2,3,4,5,6,7,8,9,10};
    vector<double> vector2 = {1,2,3,4,5,6,7,8,9,10};
    
    Matrix A{vector1, 5, 2};
    Matrix B{vector2, 10, 1};

    //+
    CHECK_THROWS(A + B);
    CHECK_THROWS(B + A);
    //-
    CHECK_THROWS(A - B);
    CHECK_THROWS(B - A);
    //*
    CHECK_THROWS(A * B);
    CHECK_THROWS(B * A);
    //*=
    CHECK_THROWS(A *= B);
    CHECK_THROWS(B *= A);
    //+=
    CHECK_THROWS(A += B);
    CHECK_THROWS(B += A);
    //-=
    CHECK_THROWS(A -= B);
    CHECK_THROWS(B -= A);
    //<
    CHECK_THROWS(bool ans = A < B);
    CHECK_THROWS(bool ans = B < A);
    //>
    CHECK_THROWS(bool ans = A > B);
    CHECK_THROWS(bool ans = B > A);
    //<=
    CHECK_THROWS(bool ans = A <= B);
    CHECK_THROWS(bool ans = B <= A);
    //>=
    CHECK_THROWS(bool ans = A >= B);
    CHECK_THROWS(bool ans = B >= A);
    //!=
    CHECK_THROWS(bool ans = A != B);
    CHECK_THROWS(bool ans = B != A);
    //==
    CHECK_THROWS(bool ans = A == B);
    CHECK_THROWS(bool ans = B == A);
}

TEST_CASE ("GOOD CASES: MULT/ADD/SUB AND BOOLEAN OPERATORS") {
    
    vector<double> vector1;     
    for (double i = 0; i < 100; ++i) {
        vector1.push_back(i);
    }

    vector<double> vector2;
    for (double i = 100; i < 200; ++i) {
        vector2.push_back(i);
    }

    vector<double> add_vector1_vector2;
    for (double i = 0; i < 100; ++i) {
        add_vector1_vector2.at(i) = vector1.at(i) + vector2.at(i);
    }
    
    vector<double> sub_vector2_vector1;
    for (double i = 0; i < 100; ++i) {
        sub_vector2_vector1.at(i) = vector2.at(i) - vector1.at(i);
    }

    vector<double> zero_vector;
    for (double i = 0; i < 100; ++i) {
        zero_vector.push_back(0);
    }

    vector<double> negative_numbers_vector;
    for (double i = 0; i < 100; ++i) {
        negative_numbers_vector.push_back(-i);
    }
  
    vector<double> mixed_vector;
    for (int i = 0; i < 100; ++i) {
        if(i % 3  == 1) {
            mixed_vector.push_back(i);
        } else if(i % 3 == 2) {
            mixed_vector.push_back(-i);
        } else {
            mixed_vector.push_back(10/(double)(100+i));
        }
    }
    

        SUBCASE("OPERATOR +") {
            //10*10 matrices
            Matrix A{vector1, 10, 10};
            Matrix B{vector2, 10, 10};
            Matrix C{add_vector1_vector2, 10, 10};
            Matrix D{zero_vector, 10, 10};
            Matrix E{negative_numbers_vector, 10, 10};
            Matrix F{mixed_vector, 10, 10};

            CHECK_EQ((A+B)==C, true);
            CHECK_EQ((A+D)==A, true);
            CHECK_EQ((A+E)==D, true);
            CHECK_EQ((F+D)==F, true);
            CHECK_EQ((D+D)==D, true);

            //50*2 matrices
            Matrix A1{vector1, 50, 2};
            Matrix B1{vector2, 50, 2};
            Matrix C1{add_vector1_vector2, 50, 2};
            Matrix D1{zero_vector, 50, 2};
            Matrix E1{negative_numbers_vector, 50, 2};
            Matrix F1{mixed_vector, 50, 2};

            CHECK_EQ((A1+B1)==C1, true);
            CHECK_EQ((A1+D1)==A1, true);
            CHECK_EQ((A1+E1)==D1, true);
            CHECK_EQ((F1+D1)==F1, true);
            CHECK_EQ((D1+D1)==D1, true);
        }

        SUBCASE("OPERATOR -") {
            //10*10 matrices
            Matrix A{vector1, 10, 10};
            Matrix B{vector2, 10, 10};
            Matrix C{sub_vector2_vector1, 10, 10};
            Matrix D{zero_vector, 10, 10};
            Matrix E{negative_numbers_vector, 10, 10};
            Matrix F{mixed_vector, 10, 10};

            CHECK_EQ((B-A)==C, true);
            CHECK_EQ((A-D)==A, true);
            CHECK_EQ((D-A)==E, true);
            CHECK_EQ((F-D)==F, true);
            CHECK_EQ((B-B)==D, true);

            //50*2 matrices
            Matrix A1{vector1, 50, 2};
            Matrix B1{vector2, 50, 2};
            Matrix C1{sub_vector2_vector1, 50, 2};
            Matrix D1{zero_vector, 50, 2};
            Matrix E1{negative_numbers_vector, 50, 2};
            Matrix F1{mixed_vector, 50, 2};

            CHECK_EQ((B1-A1)==C1, true);
            CHECK_EQ((A1-D1)==A1, true);
            CHECK_EQ((D1-A1)==E1, true);
            CHECK_EQ((F1-D1)==F1, true);
            CHECK_EQ((B1-B1)==D1, true);
        }

        SUBCASE("OPERATOR *") {
            vector<double> vector1 = {11,3,7,11};
            vector<double> vector2 = {8,0,1,0,3,5};
            vector<double> zero_vector = {0,0,0,0,0,0};
            vector<double> one_vector = {1,1,1,1,1,1};
            vector<double> mult_1_2 = {88,9,26,56,33,62};

            Matrix A{vector1, 2, 2};
            Matrix B{vector2, 2, 3};
            Matrix C{mult_1_2, 2, 3};
            Matrix D{zero_vector, 2, 3};
            Matrix E{one_vector, 2, 3};

            CHECK_EQ((A*B)==C, true);
            CHECK_EQ((D*B)==D, true);
            CHECK_EQ((E*B)==B, true);
            CHECK_EQ((0*B)==D, true);            
            CHECK_EQ((1*B)==B, true);
            CHECK_EQ((B*0)==D, true);            
            CHECK_EQ((B*1)==B, true);             
            
        }

        SUBCASE("BOOLEAN OPERATORS") {
            //10*10 matrices
            Matrix A{vector1, 10, 10};
            Matrix B{vector1, 10, 10};
            Matrix C{zero_vector, 10, 10};
            Matrix E{negative_numbers_vector, 10, 10};

            CHECK_EQ(A==B, true);
            CHECK_EQ(A<=B, true);
            CHECK_EQ(A>=B, true);
            CHECK_EQ(A!=C, true);
            CHECK_EQ(E<A, true);
            CHECK_EQ(C>E, true);
        }

        SUBCASE("*=/-=/+=") {
            vector<double> vector1 = {1,2,3,4,5,6};
            vector<double> vector2 = {1,1,1,1,1,1};
            vector<double> vector3 = {0,0,0,0,0,0};

            Matrix A{vector1, 3, 2};
            Matrix B{vector2, 3, 2};
            Matrix C{vector3, 3, 2};     

            CHECK_EQ((A+=C)==A, true);
            CHECK_EQ((A-=C) == B, true);
            CHECK_EQ((A*=C) == C, true);
        }

        SUBCASE("UNARY OPERATORS") {
            Matrix A{vector1, 10, 10};
            Matrix B{vector1, 10, 10};
            Matrix C{negative_numbers_vector, 10, 10};

            CHECK_EQ((+A)==B, true);
            CHECK_EQ((-A)==C, true);
        }

        
}

TEST_CASE ("GOOD CASES: INCREAMENT OPERTORS") {
        vector<double> vector1;     
        for (double i = 0; i < 100; ++i) {
            vector1.push_back(i);
        }

        vector<double> vector1_increament_by_one;     
        for (double i = 0; i < 100; ++i) {
            vector1.push_back(i+1);
        }
        
        vector<double> vector1_decrease_by_one;     
        for (double i = 0; i < 100; ++i) {
            vector1.push_back(i-1);
        }

        Matrix A{vector1, 10, 10};
        Matrix B{vector1_increament_by_one, 10, 10};
        Matrix C{vector1_decrease_by_one, 10, 10};

        CHECK_EQ((A++)==A, true);
        CHECK_EQ((++A)==B, true);
        CHECK_EQ((A--)==A, true);
        CHECK_EQ((--A)==C, true);
        CHECK_NOTHROW(A*3);
}

TEST_CASE ("CONSTRUCTOR: NOT APPROPRIATE PARAMETERS") {
    vector<double> vector1 = {1,2,3,4,5,6,7};
    CHECK_THROWS(Matrix(vector1, 5, 2));
    CHECK_THROWS(Matrix(vector1, 4, 2));
    CHECK_THROWS(Matrix(vector1, -1, 2));
    CHECK_THROWS(Matrix(vector1, 4, 0));
    
}
