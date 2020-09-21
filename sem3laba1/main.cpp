//
//  main.cpp
//  sem3laba1
//
//  Created by Данил Морозов on 13/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//
#ifndef main_h
#define main_h
#include <iostream>
#include "header.h"
#endif

int main() {
    Table* table;
    bool (*universal_function)(int) = universal_bool_function;
    table = new Table;
    table->first = nullptr;
    std::cout << std::endl << "Please, enter table size" << std::endl;
    int a = 0, b = 0, i = 0;
    std::cout << "Пожалуйста, нажмите Enter" << std::endl;
    while (i == 0) {
        std::cout << "Введите количество строк" << std::endl;
        getNum(a);
        std::cout << "Введите количество столбцов" << std::endl;
        getNum(b);
        if ((a > 0) & (b > 0))
            i = 1;
        else
            std::cout << "**********Ввод значений строки и столбца не засчитаны: обнаружены неположительные значения" << std::endl;
    }
    table->a = a;
    table->b = b;
    int (*func[])(Table*) = {nullptr, create, draw, deletion};
    int k = 0, n = 0;
    while (k == 0) {
        std::cout << "Что вы хотите сделать с таблицей?"<< std::endl <<"0. Закончить работу и освободить выделенную память"<< std::endl << "1. Добавить узлы" << std::endl << "2. Вывести таблицу" << std::endl << "3. Отбор четных элементов и сортировка строк по возрастанию количетва ненулевых элементов"<< std::endl;
        std::cin >> n;
        if (n == 0) {
           return 0;
        }
        printf("вызываю функцию номер:%d\n", n);
        if (n == 3) {
            sort(table, universal_function);
        }
        else
            func[n](table);
    }
    deletion (table);
    return 0;
}
