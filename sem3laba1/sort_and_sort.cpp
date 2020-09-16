//
//  sort_and_sort.cpp
//  sem3laba1
//
//  Created by Данил Морозов on 16/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "sort_and_sort.h"

int sort (Table * table) {
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
            if ((gori->number % 2) == 1) {
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
 //   std::cout << "k = " << k << std::endl;
    k = table->a - k + 1;
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
    return 0;
}
