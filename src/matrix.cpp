//
// Created by rudri on 3/23/2022.
//

#include "matrix.h"
#include <stdexcept>
#include <format>

void utec::matrix::create_matrix(TYPE**& matrix, SIZE_TYPE nr, SIZE_TYPE nc) const {
    matrix = new TYPE*[n_rows]{};
    for (SIZE_TYPE i = 0; i < n_rows; ++i) {
        matrix[i] = new TYPE[n_cols]{};
    }
}

utec::matrix::matrix(SIZE_TYPE n_rows, SIZE_TYPE n_cols):
        n_rows{n_rows}, n_cols{n_cols} {
    create_matrix(data, n_rows, n_cols);
}

TYPE& utec::matrix::operator()(SIZE_TYPE row, SIZE_TYPE col) {
    if (data == nullptr)
        throw std::runtime_error("matrix was not initialized");
    return data[row][col];
}

TYPE utec::matrix::operator()(SIZE_TYPE row, SIZE_TYPE col) const {
    if (data == nullptr)
        throw std::runtime_error("matrix was not initialized");
    return data[row][col];
}

[[nodiscard]] SIZE_TYPE utec::matrix::col_size() const {
    return n_cols;
}

[[nodiscard]] SIZE_TYPE utec::matrix::row_size() const {
    return n_rows;
}

std::ostream& utec::operator<<(std::ostream &os, const utec::matrix &m) {
    for (int i = 0; i < m.n_rows; ++i) {
        for (int j = 0; j < m.n_cols; ++j) {
            os << m(i, j);
        }
        os << std::endl;
    }
    return os;
}