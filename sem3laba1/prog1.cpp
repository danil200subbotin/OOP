//
//  prog1.cpp
//  sem3laba1
//
//  Created by Данил Морозов on 20/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include <stdio.h>
#include "header.h"


int create (Table* table) {
    Vertical* vert = nullptr;
    Vertical* prev = nullptr;
    Gorizontal* gori = nullptr;
    gori = new Gorizontal;
    int i = 0, j = 0, n = 0, k = 0;
    std::cout << "Вводите тройки чисел через пробел [строка, слолбец, значение ячейки]" << std::endl << "Для конца ввода введите 3 нуля" << std::endl;
    std::cout << "Чтобы прекратить ввод элементов, наберите 3 нуля подряд" << std::endl;
    if (table->first == nullptr) {
        while (k == 0) {
            std::cout << "Ведите номер строки нового элемента" << std::endl;
            getNum(i);
            std::cout << "Ведите номер столбца нового элемента" << std::endl;
            getNum(j);
            std::cout << "Ведите значение нового элемента" << std::endl;
            getNum(n);
            if ((i == 0) && (j == 0) && (n == 0)) {
                return 0;
            }
            if ((i > 0) & (j > 0) & (i <= table->a) & (j <= table->b))
                k = 1;
            else
                std::cout << "**********Ввод элемента не засчитан: обнаружены неположительные значения" << std::endl;
        }
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
        k = 0;
        while (k == 0) {
            std::cout << "Ведите номер строки нового элемента" << std::endl;
            getNum(i);
            std::cout << "Ведите номер столбца нового элемента" << std::endl;
            getNum(j);
            std::cout << "Ведите значение нового элемента" << std::endl;
            getNum(n);
            if ((i == 0) && (j == 0) && (n == 0)) {
                return 0;
            }
            if ((i > 0) & (j > 0)  & (i <= table->a) & (j <= table->b))
                k = 1;
            else
                std::cout << "**********Ввод элемента не засчитан: обнаружены неположительные значения" << std::endl;
        }
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



void add_string(Table* table, Vertical* vert, Vertical* prev, int i, int j, int n) {
    Vertical* vertnew = new Vertical;
    Gorizontal* gorinew = new Gorizontal;
    vertnew->count = 1;
    vertnew->i = i;
    if (vert != nullptr) {
        if (prev != nullptr) {
            vertnew->down = prev->down;
            prev->down->up = vertnew;
            prev->down = vertnew;
            vertnew->up = prev;
        }
        else {
            vertnew->down = table->first;
            table->first->up = vertnew;
            table->first = vertnew;
            vertnew->up = nullptr;
        }

    }
    else {
        vertnew->down = nullptr;
        prev->down = vertnew;
    }
    vertnew->right = gorinew;
    gorinew->j = j;
    gorinew->number = n;
    gorinew->right = nullptr;
    gorinew->left = nullptr;
    return;
    
}


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


void sort2 (int k, Sort* beginning, Table* table, Vertical* vert) {
//   std::cout << "k = " << k << std::endl;
    k = table->a - k + 1;
    Sort* sort = nullptr;
    Sort* shelper = nullptr;
 //   std::cout << "k = " << k << std::endl;
    sort = beginning;
    table->first = beginning->vert;
    table->first->i = k;
    k++;
    vert = table->first;
    while (sort->next != nullptr) {
        vert->down = sort->next->vert;
        vert = vert->down;
        vert->i = k;
        k++;
        sort = sort->next;
    }
    vert->down = nullptr;
//    std::cout << "k = " << k << std::endl;
    shelper = beginning;
    while (shelper!= nullptr) {
        beginning = shelper->next;
        delete shelper;
        shelper = beginning;
    }
}

bool universal_bool_function (int parametr) {
    if (parametr % 2 == 1)
        return 1;
    return 0;
}

int sort (Table * table, bool (*universal_function)(int)) {
    int k = 0;
    if (table->first == nullptr) return 1;
    Vertical* vert = table->first;
    Sort* sort = nullptr;
    Sort* beginning = nullptr;
    Sort* shelper = nullptr;
    Gorizontal* gori;
    Gorizontal* helper;
    while(vert != nullptr) {
        gori = vert->right;
        while (gori != nullptr) {
            if (universal_function(gori->number)) {
                vert->count--;
                if (gori->left == nullptr) {
                    vert->right = gori->right;
                }
                else {
                    gori->left->right = gori->right;
                }
                helper = gori;
                gori = gori->right;
                if (gori != nullptr) {
                    helper->right->left = helper->left;
                }
                delete helper;
            }
            else {
                gori = gori->right;
            }
        }
        if (beginning == nullptr) {
            sort = new Sort;
            sort->next = nullptr;
            sort->prev = nullptr;
            sort->vert = vert;
            beginning = sort;
            k++;
        }
        else {
            sort = beginning;
            while ((sort->vert->count < vert->count) && (sort->next != nullptr)){
                sort = sort->next;
            }
            shelper = new Sort;
            shelper->vert = vert;
            if (sort->vert->count <= vert->count) {
                shelper->prev = sort;
                shelper->next = sort->next;
                sort->next = shelper;
                if (shelper->next != nullptr) {
                    shelper->next->prev = shelper;
                }
                k++;
            }
            if (sort->vert->count > vert->count) {
                k++;
                if (sort->prev == nullptr) {
                    shelper->next = sort;
                    sort->prev = shelper;
                    shelper->prev = nullptr;
                    beginning = shelper;
                }
                else {
                    shelper->prev = sort->prev;
                    sort->prev->next = shelper;
                    shelper->next = sort;
                    sort->prev = shelper;
                }
            }
        }
        vert = vert->down;
    }
    
    
    sort2 (k, beginning, table, vert);
    return 0;
}
 

int deletion(Table* table) {
    Gorizontal* gori = nullptr;
    Gorizontal* ghelper = nullptr;
    Vertical* vert = nullptr;
    Vertical* vhelper = nullptr;
    if (table->first == nullptr) {
        delete table;
        return 0;
    }
    vert = table->first;
    while (vert != nullptr) {
        gori = vert->right;
        while (gori != nullptr) {
            ghelper = gori->right;
            delete gori;
            gori = ghelper;
        }
        vhelper = vert->down;
        delete vert;
        vert = vhelper;
    }
    return 0;
}




//нужные (возможно) запчасти


 //   std::cout << "k = " << k << std::endl;
/* k = table->a - k + 1;
 //   std::cout << "k = " << k << std::endl;
    //sort2 (k, beginning, table, vert);
    sort = beginning;
    table->first = beginning->vert;
    table->first->i = k;
    k++;
    vert = table->first;
    while (sort->next != nullptr) {
        vert->down = sort->next->vert;
        vert = vert->down;
        vert->i = k;
        k++;
        sort = sort->next;
    }
    vert->down = nullptr;
//    std::cout << "k = " << k << std::endl;
    shelper = beginning;
    while (shelper!= nullptr) {
        beginning = shelper->next;
        delete shelper;
        shelper = beginning;
    }
 */
