#include "ConsoleDeco.h"

void setFontColor(enum color colorType) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch(colorType) {
        // Font color: white
        case white:
            SetConsoleTextAttribute(hConsole, 15);
        break;

        // Font color: green
        case green:
            SetConsoleTextAttribute(hConsole, 10);
        break;

        // Font color: yellow
        case yellow:
            SetConsoleTextAttribute(hConsole, 14);
        break;

        // Font color: red
        case red:
            SetConsoleTextAttribute(hConsole, 12);
        break;
    }
}
