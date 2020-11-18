#include <curses.h>

#include "common.h"



char *test[6] = { "*****", "*@*@*" };



int main()
{
        initscr();
        curs_set(0);
        DrawObject(test, 0, 0, 5, 2);
        getch();
        endwin();

        return 0;
}
