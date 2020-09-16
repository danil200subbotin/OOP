//
//  deletion.cpp
//  sem3laba1
//
//  Created by Данил Морозов on 16/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "deletion.hpp"


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
