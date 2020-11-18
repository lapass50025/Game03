#include <curses.h>

#include "common.h"

int main()
{
        initscr();
        curs_set(0);
        printw("Hello Ncurses!!!");
        getch();
        endwin();

        return 0;
}
