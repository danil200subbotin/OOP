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
