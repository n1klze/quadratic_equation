# Решение квадратных уравнений
## quadratic_equation
[Оригинальное задание](https://sblnk.ru/620442694)
## Описание
Модуль quadratic_equation содержит реализацию функции solve_equation.  
Аргументы функции — 3 вещественных числа $a$, $b$, $c$. Функция решает квадратное уравнение $ax^2+bx+c=0$. Возвращает структуру, хранящую количество действительных корней и их значение.
## Сборка и запуск
1. Склонируйте репозиторий
   ```
   git clone https://github.com/n1klze/quadratic_equation.git
   ```
2. Сгенерируйте файлы сборки
    ```
    mkdir build && cd build
    cmake -DCMAKE_BUILD_TYPE=Release ..
    ```
3. Соберите проект
    ```
    make
    ```
4. Протестируйте модуль
    ```
    make check
    ```
5. 
    ```
    sudo make install
    ```