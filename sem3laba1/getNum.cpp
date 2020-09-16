//
//  getNum.cpp
//  sem3laba1
//
//  Created by Данил Морозов on 16/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "getNum.hpp"

//template <class T>
int  getNum (int a) {
    std::cin.clear();
    std::cin >> a;
    if (!std::cin.good())
        return 1;
    return 0;
}
