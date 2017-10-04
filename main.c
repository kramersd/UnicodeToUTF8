//
//  main.c
//  UnicodeToUTF8
//
//  Created by Shane Kramer on 10/3/17.
//  Copyright © 2017 kramersd. All rights reserved.
//

#include <stdio.h>

void convertAndPrint(int unicode) {
    if(unicode <= 0x7F) {
        if(unicode < 0) {
            printf("%x : %x\n", unicode,  0xFFFFFFFF);
            return;
        }
        printf("%x : %x\n", unicode, unicode);
    } else if(unicode <= 0x7FF) {
        int a = (0x7C0 & unicode) << 2;
        int b =  0x3F & unicode;
        int output =  0xC080 | a | b;
        printf("%x : %x\n", unicode, output);
        return;
        
    } else if(unicode <= 0xFFFF) {
        int a = (0xF000 & unicode) << 4;
        int b = (0x0FC0 & unicode) << 2;
        int c = 0x003F & unicode;
        int output = 0xE08080 | a | b | c;
        printf("%x : %x\n", unicode, output);
         return;
        
    } else if(unicode <= 0x10FFFF) {
        int a = (0x1C0000 & unicode) << 6;
        int b = (0x03F000 & unicode) << 4;
        int c = (0x000FC0 & unicode) << 2;
        int d = 0x00003F & unicode;
        int output = 0xF0808080 | a | b | c | d;
        printf("%x : %x\n", unicode, output);
         return;
    } else {
        printf("%x : %x\n", unicode,  0xFFFFFFFF);
         return;
    }
}

int main(int arg, const char * argv[]) {
    int testValues[17] = {0x0000, 0x0024, 0x007E, 0x007F, 0x0080, 0x00A2, 0x0627, 0x07FF,
        0x0800, 0x20AC, 0x2233, 0xFFFF, 0x10000, 0x10348, 0x22E13, 0x10FFFF, 0x89ABCDEF};
    printf("Unicode : UTF8\n");
    for(int i = 0; i < 17; i++) {
        convertAndPrint(testValues[i]);
    }
    return 0;
}
