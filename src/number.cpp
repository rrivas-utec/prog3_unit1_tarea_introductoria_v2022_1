//
// Created by rudri on 3/23/2022.
//

#include "number.h"

std::ostream& operator << (std::ostream& os, number_t* number) {
    if (dynamic_cast<integer_t*>(number) != nullptr)
        os << int(*number);
    else if (dynamic_cast<real_t*>(number) != nullptr)
        os << double(*number);
    return os;
}