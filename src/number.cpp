//
// Created by rudri on 3/23/2022.
//

#include "number.h"

std::ostream& operator << (std::ostream& os, const number_t* number) {
    os << int(*number);
return os;
}