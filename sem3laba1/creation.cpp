//
//  creation.cpp
//  sem3laba1
//
//  Created by Данил Морозов on 13/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//
#include "drawing.h"
#include "creation.h"

int create (Table* table) {
    Vertical* vert = nullptr;
    Vertical* prev = nullptr;
    Gorizontal* gori = nullptr;
    gori = new Gorizontal;
    int i = 0, j = 0, n = 0;
    std::cout << "Вводите тройки чисел через пробел [строка, слолбец, значение ячейки]" << std::endl << "Для конца ввода введите 3 нуля" << std::endl;

    if (table->first == nullptr) {
    std::cin >> i >> j >> n;
    if ((i == 0) && (j == 0) && (n == 0)) {
        return 0;
    }
    vert = new Vertical;
    table->first = vert;
    vert->i = i;
    vert->up = nullptr;
    vert->down = nullptr;
    vert->count = 1;
    gori->j = j;
    gori->number = n;
    gori->right = nullptr;
    gori->left = nullptr;
    vert->right = gori;
//    return 0;
    }
    while (1) {
        std::cin >> i >> j >> n;
        if ((i == 0) && (j == 0) && (n == 0)) {
            return 0;
        }
        vert = table->first;
        while ((vert != nullptr) && (vert->i < i)) {
//            std::cout << "--1" << std::endl;
            prev = vert;
            vert = vert->down;
        }
        if ((vert == nullptr) || (vert->i != i)) {
            add_string(table, vert, prev, i, j, n);
            
            continue;
        }
        if (vert->i == i) {
            gori = vert->right;
            if (gori == nullptr) {
                gori = new Gorizontal;
                vert->right = gori;
                gori->j = j;
                gori->left = nullptr;
                gori->right = nullptr;
                gori->number = n;
                continue;
            }

            while ((gori->right != nullptr) && (gori->j < j)){
                gori = gori->right;
            }
            if (gori->j == j) {
                std::cout << "перезаписываю этот элемент" << std::endl;
                gori->number = n;
                continue;
            }
            vert->count++;
            Gorizontal* gorinew = new Gorizontal;
            if (gori->j > j) {
                gorinew->left = gori->left;
                gorinew->right = gori;
                if (gori->left == nullptr) {
                    vert->right = gorinew;
                }
                else {

                    gori->left->right = gorinew;
                }
                gori->left = gorinew;
                gorinew->number = n;
                gorinew->j = j;
                continue;
            }
            if (gori->j < j) {
                
                gorinew->left = gori;
                gori->right = gorinew;
                gorinew->number = n;
                gorinew->j = j;
                gorinew->right = nullptr;
  //              draw(table);
                continue;
            }
        }
    }
}
