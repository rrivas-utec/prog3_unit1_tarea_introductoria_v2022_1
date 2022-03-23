# Task #1: Tarea Introductoria - Matriz  
**course:** Programación III  
**unit:** 1  
**cmake project:** prog3_unit1_tarea_introductoria_v2022_1
## Instructions
Subir a gradescope los siguientes archivos:

- **`matrix.h` y `matrix.cpp`**, contienen la declaración (.h) y definición (.cpp) de la clase **`matrix_t`**
- **`number.h` y `number.cpp`**, contienen, contienen la declaración (.h) y definición (.cpp) de las clases **`number_t`** y de funciones adicionales derivadas de `number_t`: `integer_t`, `real_t` y `complex_t`.

## Question #1 - Matriz (20 points)
  
Desarrollar una matriz polimórfica que acepte diferentes tipos numéricos (entero, reales, imaginarios) 
  
**Use Case:**  
```cpp
    utec::matrix m1(4, 5);
    for (int i = 0; i < m1.row_size(); ++i) {
        for (int j = 0; j < m1.col_size(); ++j) {
            m1(i, j) = new integer_t(rand() % 100);
        }
    }
    std::cout << m1;
    utec::matrix m2 = m1;
    
    for (int i = 0; i < m2.row_size(); ++i) {
        for (int j = 0; j < m2.col_size(); ++j) {
            m2(i, j) = new real_t(rand() % 100);
        }
    }
    std::cout << m1;
    std::cout << m2;
```