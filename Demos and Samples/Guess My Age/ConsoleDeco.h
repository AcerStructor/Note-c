#ifndef _CONSOLEDECO_H_
#define _CONSOLEDECO_H_
#include <windows.h>

enum color {
    white,
    yellow,
    green,
    red
};

void setFontColor(enum color colorType);

#endif // _CONSOLEDECO_H_
