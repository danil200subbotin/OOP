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
#include "creation.h"
#include "drawing.h"
#include "sort_and_sort.h"
#include "deletion.hpp"
#include "getNum.hpp"
#endif

int main() {
    Table* table;
    table = new Table;
    table->first = nullptr;
    std::cout << "Please, enter table size\n" << std::endl;
    int a = 0, b = 0, i = 1;
 /*   while (i == 1) {
        i = getNum(a);
    }
    i = 1;
    while (i == 1) {
        i = getNum(b);
    }
    */
    std::cin >> a >> b;
    table->a = a;
    table->b = b;
    int (*func[])(Table*) = {nullptr, create, draw, sort, deletion};
    int k = 0, n = 0;
    while (k == 0) {
        std::cout << "Что вы хотите сделать с таблицей?"<< std::endl <<"0. Закончить работу и освободить выделенную память"<< std::endl << "1. Добавить узлы" << std::endl << "2. Вывести таблицу" << std::endl << "3. Отбор четных элементов и сортировка строк по возрастанию количетва ненулевых элементов"<< std::endl;
        std::cin >> n;
               if (n == 0) {
                   return 0;
               }
               printf("вызываю функцию номер:%d\n", n);
               func[n](table);
    }
    deletion (table);
    return 0;
}
