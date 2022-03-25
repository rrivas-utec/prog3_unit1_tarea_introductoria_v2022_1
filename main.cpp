#include <iostream>
#include <vector>
#include "number.h"


int main() {
    std::vector<number_t*> v1 = {
            new real_t(1),
            new integer_t(2),
            new real_t(10.5)};
    for (const auto& n: v1) {
        std::cout << n << " ";
    }
    return 0;
}
