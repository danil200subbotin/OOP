//
//  drawing.cpp
//  sem3laba1
//
//  Created by Данил Морозов on 15/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "drawing.h"
#include <iomanip>

int draw (Table* table) {
    std::cout << "начинаем рисование" << std::endl;
    if (table->first == nullptr) {
         for (int a = 1; a <= table->a; a++) {
             for (int j = 1; j <= table->b; ++j) {
                 std::cout << "0 ";
             }
             std::cout << std::endl;
         }
        return 0;
    }
    Vertical* vert = table->first;
    Gorizontal* goriz = nullptr;
    for (int a = 1; a <= table->a; a++) {
        if ((vert->i > a) || (vert->i < a) || (vert->count == 0)) {
            for (int j = 1; j <= table->b; ++j) {
                std::cout << std::setw(5) << "0";
                if ((vert->count == 0) && (vert->down != nullptr)) {
//                    std::cout << " count = " << vert->count;
                    vert = vert->down;
                }
            }
            std::cout << std::endl;
            std::cout << std::endl;
            continue;
        }
        goriz = vert->right;
        for (int b = 1; b <= table->b; b++) {
            if ((goriz->j > b) || (goriz->j < b)) {
  //              int ff = goriz->j;
//                int f = goriz->number;
                std::cout << std::setw(5) << "0";
                continue;
            }
            std::cout << std::setw(5) << goriz->number;
            if (goriz->right != nullptr) {
                goriz = goriz->right;
            }
        }
 //       std::cout << " count = " << vert->count;
        std::cout << std::endl;
        std::cout << std::endl;
        
        if (vert->down != nullptr) vert = vert->down;
    }
    return 0;
}
