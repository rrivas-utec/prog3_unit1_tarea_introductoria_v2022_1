//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "matrix.h"
#include "number.h"
#include <random>
#include <iostream>
using namespace std;

static void question_1_1() {
    utec::matrix m1(10, 20);
    random_device rd;
    uniform_int_distribution<int> dis(0, 100);

    for (int i = 0; i < m1.row_size(); ++i) {
        for (int j = 0; j < m1.col_size(); ++j) {
            m1(i, j) = new integer_t(dis(rd));
        }
    }
    utec::matrix m2 = m1;

    for (int i = 0; i < m2.row_size(); ++i) {
        for (int j = 0; j < m2.col_size(); ++j) {
            m2(i, j) = new real_t(dis(rd));
        }
    }
    cout << m1.row_size() << " " << m1.col_size() << endl;
    cout << m2.row_size() << " " << m2.col_size() << endl;
}

TEST_CASE("Question #1_1") {
    execute_test("test_1_1.in", question_1_1);
}