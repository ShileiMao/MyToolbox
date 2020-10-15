//
//  StandardOut.h
//  MyToolbox
//
//  Created by Shilei Mao on 15/10/2020.
//

#ifndef StandardOut_h
#define StandardOut_h

#include <stdio.h>

#define println(fmt, ...) printf(fmt, __VA_ARGS__);\
        printf("\n")

#endif /* StandardOut_h */
