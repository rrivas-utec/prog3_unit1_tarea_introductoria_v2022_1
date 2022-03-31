//
// Created by rudri on 3/23/2022.
//

#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H

#include "number.h"
#include <iostream>

using TYPE = number_t*;
using SIZE_TYPE = unsigned int;

namespace utec {
    class matrix {
        TYPE** data = nullptr;
        SIZE_TYPE n_rows = 0;
        SIZE_TYPE n_cols = 0;
        void create_matrix(TYPE**& matrix, SIZE_TYPE nr, SIZE_TYPE nc) const;
    public:
        matrix(SIZE_TYPE n_rows, SIZE_TYPE n_cols);
        TYPE& operator ()(SIZE_TYPE row, SIZE_TYPE col);
        TYPE operator ()(SIZE_TYPE row, SIZE_TYPE col) const;
        [[nodiscard]] SIZE_TYPE row_size() const;
        [[nodiscard]] SIZE_TYPE col_size() const;
        friend std::ostream& operator <<(std::ostream& os, const matrix& m);
    };
    std::ostream& operator <<(std::ostream& os, const matrix& m);
}

#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
