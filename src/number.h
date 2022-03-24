//
// Created by rudri on 3/23/2022.
//

#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_NUMBER_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_NUMBER_H

#include <iostream>

class number_t {
public:
    [[nodiscard]] virtual number_t* get_value() const = 0;
    virtual void set(number_t* value) = 0;
    virtual explicit operator int() const = 0;
    virtual explicit operator double () const = 0;
};

class integer_t: public number_t {
    int value = 0;
public:
    integer_t() = default;
    integer_t(int value): value{value} {}
    [[nodiscard]] number_t* get_value() const override
    { return new integer_t(value); }
    void set(number_t* number) override
    {  value = int(number); }
    explicit operator int() const override { return value; }
    explicit operator double () const override  { return value; }
    friend std::ostream& operator << (std::ostream& os, const number_t* number);
};

class real_t: public number_t {
    double value = 0;
public:
    real_t() = default;
    real_t(double value): value{value} {}
    [[nodiscard]] real_t* get_value() const override {
        return new real_t(value);
    }

    void set(number_t* number) override {
        value = double(*number);
    }
    explicit operator int() const override {
        return static_cast<int>(value);
    }
    explicit operator double () const override { return value; }
    friend std::ostream& operator << (std::ostream& os, const number_t* number);
};

std::ostream& operator << (std::ostream& os, const number_t* number);

#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_NUMBER_H
