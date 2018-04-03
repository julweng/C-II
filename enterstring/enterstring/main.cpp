//
//  main.cpp
//  enterstring
//
//  Created by 資雅 翁 on 4/30/17.
//  Copyright © 2017 Julia Weng. All rights reserved.
//

#include <iostream>
int main()
{
    int x = 5;
    float y = 5.6;
    double z = 5.88;
    void *p = NULL;
    short int a = 1;

    std::cout << "int is " << sizeof(x) << " byte\n";
    std::cout << "float is " << sizeof(y) << " byte\n";
    std::cout << "double is " << sizeof(z) << " byte\n";
    std::cout << "pointer is " << sizeof(p) << " byte\n";
    std::cout << "short is " << sizeof(a) << " byte\n";
    
    struct Test
    {
        float flt;
        double dbl;
        void *vp;
    };

    std::cout << "the float is at offset " << offsetof(Test, flt) << '\n';
    std::cout << "the double is at offset " << offsetof(Test, dbl) << '\n';
    //std::cout << "the pointer is at offset " << offsetof(Test, void *) << '\n';

    return (0);
}
