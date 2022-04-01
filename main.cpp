#include <iostream>
#include <vector>
#include <random>
#include "number.h"
#include "matrix.h"
using namespace std;

void matrix_test() {
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
    cout << m1 << endl;
    cout << m1.row_size() << " " << m1.col_size() << endl;
    cout << m2.row_size() << " " << m2.col_size() << endl;
}

void number_test() {
    std::vector<number_t*> v1 = {
            new real_t(1),
            new integer_t(2),
            new real_t(10.5)};
    for (const auto& n: v1) {
        std::cout << n << " ";
    }
}

int main() {
    matrix_test();
    return 0;
}
