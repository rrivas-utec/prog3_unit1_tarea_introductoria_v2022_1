//
// Created by rudri on 3/23/2022.
//

#pragma once
#include <iostream>

using TYPE = int;
using SIZE_TYPE = size_t;

namespace utec {
    class matrix {
        TYPE* data = nullptr;
        SIZE_TYPE n_rows = 0;
        SIZE_TYPE n_cols = 0;
    public:
        explicit matrix(SIZE_TYPE rows, SIZE_TYPE cols);
        matrix(const matrix& other);
        matrix& operator=(const matrix& other);
        matrix(matrix&& other) noexcept;
        matrix& operator=(matrix&& other) noexcept;
        ~matrix();
        TYPE& operator () (SIZE_TYPE row, SIZE_TYPE col);
        TYPE operator () (SIZE_TYPE row, SIZE_TYPE col) const;
        [[nodiscard]] SIZE_TYPE rows() const;
        [[nodiscard]] SIZE_TYPE cols() const;
        matrix operator + (const matrix& other) const;
        matrix operator * (const matrix& other) const;
        matrix operator *= (TYPE scalar) const;
        bool operator == (const matrix& other) const;
        bool operator != (const matrix& other);
        friend std::ostream& operator << (std::ostream& os, const matrix& m);
        friend matrix operator * (const matrix& m, TYPE scalar);
        friend matrix operator * (TYPE scalar, const matrix& m);
    };
    std::ostream& operator << (std::ostream& os, const matrix& m);
    matrix operator * (const matrix& m, TYPE scalar);
    matrix operator * (TYPE scalar, const matrix& m);
}
