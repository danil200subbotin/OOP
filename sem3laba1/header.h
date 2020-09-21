//
//  header.h
//  sem3laba1
//
//  Created by Данил Морозов on 13/09/2020.
//  Copyright © 2020 Данил Морозов. All right reserved.
//
#pragma once 
#ifndef header_h
#define header_h
#include <iostream>
#include <iomanip>
#include <limits.h>
#endif /* header_h */

typedef struct Gorizontal Gorizontal;
typedef struct Table Table;
typedef struct Vertical Vertical;
typedef struct Sort Sort;

struct Table {
    int a, b;
    Vertical* first;
};

struct Vertical {
    int i, count;
    Vertical* up;
    Vertical* down;
    Gorizontal* right;
};

struct Gorizontal {
    int j, number;
    Gorizontal* right;
    Gorizontal* left;
};

struct Sort {
    Vertical* vert;
    Sort* next;
    Sort* prev;
};

int create (Table* table);

void add_string(Table*, Vertical*, Vertical*, int, int, int);

int draw (Table*);

int sort (Table*, bool(*)(int));

int deletion (Table*);

bool universal_bool_function (int);

template <class T>

int  getNum (T &a) {//проверочка ввода инта
    int i = 1;
    while (i == 1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> a;
        if (!std::cin.good())
            i = 1;
        else
            i = 0;
        if (i != 0) std::cout << "Вы ввели неприемлимое значение, повторите ввод"<< std::endl;
    }
    return 0;
}

