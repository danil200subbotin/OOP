//
//  add_string.cpp
//  sem3laba1
//
//  Created by Данил Морозов on 14/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "add_string.h"

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
