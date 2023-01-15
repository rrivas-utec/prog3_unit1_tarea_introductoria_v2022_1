//
// Created by rudri on 3/23/2022.
//

#include "matrix.h"
#include <iomanip>
#include <algorithm>

utec::matrix::matrix(SIZE_TYPE rows, SIZE_TYPE cols):
        data{new TYPE[rows * cols]},
        n_rows{rows}, n_cols{cols} {
}

utec::matrix::matrix(const utec::matrix &other):
    data(new TYPE[other.n_rows * other.n_cols]),
    n_rows{other.n_rows}, n_cols{other.n_cols} {
    std::copy(other.data, other.data + n_rows*n_cols, data);
}

utec::matrix &utec::matrix::operator=(const utec::matrix &other) {
    if (this == &other) return *this;
    delete [] data;
    data = new TYPE [other.n_rows * other.n_cols];
    n_rows = other.n_rows;
    n_cols = other.n_cols;
    std::copy(other.data, other.data + n_rows*n_cols, data);
    return *this;
}

utec::matrix::matrix(utec::matrix &&other) noexcept:
    data(other.data),
    n_rows{other.n_rows}, n_cols{other.n_cols} {
    other.data = nullptr;
    other.n_rows = other.n_cols = SIZE_TYPE {};
}

utec::matrix &utec::matrix::operator=(utec::matrix &&other) noexcept {
    if (this == &other) return *this;
    n_rows = other.n_rows;
    n_cols = other.n_cols;
    std::swap(data, other.data);
    delete [] other.data;
    other.data = nullptr;
    other.n_rows = other.n_cols = SIZE_TYPE {};
    return *this;
}

utec::matrix::~matrix() {
    delete [] data;
}

TYPE& utec::matrix::operator() (SIZE_TYPE row, SIZE_TYPE col) {
    return data[row*n_cols + col];
}

TYPE utec::matrix::operator() (SIZE_TYPE row, SIZE_TYPE col) const {
    return data[row*n_cols + col];
}

SIZE_TYPE utec::matrix::cols() const { return n_cols; }
SIZE_TYPE utec::matrix::rows() const { return n_rows; }

std::ostream& utec::operator<<(std::ostream &os, const utec::matrix &m) {
    for (size_t i = 0; i < m.n_rows; ++i) {
        for (size_t j = 0; j < m.n_cols; ++j)
            os << std::setw(4) << m.data[i*m.n_cols + j];
        os << std::endl;
    }
    return os;
}

utec::matrix utec::matrix::operator+(const utec::matrix &other) {
    if (n_rows != other.n_rows || n_cols != other.n_cols)
        throw std::runtime_error(
                "number of rows and columns does not match");
    auto result = *this;
    for (size_t i = 0; i < result.n_rows; ++i)
        for (size_t j = 0; j < result.n_cols; ++j)
            result.data[i*result.n_cols +j] += other.data[i*result.n_cols +j];
    return result;
}

utec::matrix utec::matrix::operator*(const utec::matrix &other) {
    if (n_cols != other.n_rows)
        throw std::runtime_error(
                "number of columns of first matrix does not match with rows of second matrix");

    auto result = matrix(n_rows, other.n_cols);
    for (size_t i = 0; i < result.n_rows; ++i)
        for (size_t j = 0; j < result.n_cols; ++j) {
            TYPE item = TYPE {};
            for (size_t k = 0; k < n_cols; ++k)
                item += data[i*n_cols + k] * other.data[k*other.n_cols + j];
            result.data[i*result.n_cols + j] = item;
        }
    return result;
}

utec::matrix utec::matrix::operator*=(TYPE scalar) {
    for (auto it = data; it != data + n_rows*n_cols; ++it)
        *it *= scalar;
    return *this;
}

bool utec::matrix::operator==(const utec::matrix &other) const {
    if (n_rows != other.n_rows || n_cols != other.n_cols) return false;
    auto result = true;
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_cols && result; ++j)
            result = data[i*n_cols + j] == other.data[i*n_cols + j];
    return result;
}

bool utec::matrix::operator!=(const utec::matrix &other) {
    if (n_rows != other.n_rows || n_cols != other.n_cols) return true;
    auto result = false;
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_cols && !result; ++j)
            result = data[i*n_cols + j] != other.data[i*n_cols + j];
    return result;
}

utec::matrix utec::operator*(const utec::matrix &m, TYPE scalar) {
    auto result = m;
    for (size_t i = 0; i < m.n_rows; ++i)
        for (size_t j = 0; j < m.n_cols; ++j)
            result.data[i*m.n_cols + j] = m.data[i*m.n_cols + j] * scalar;
    return result;
}

utec::matrix utec::operator*(TYPE scalar, const utec::matrix &m) { return m * scalar; }
