#include <curses.h>
#include <string.h>



int main(void)
{
    int ch = 'y';
    int nX = 0;
    int nY = 0;



    // 터미널 초기화하기
    initscr();
    curs_set(0);

    nY = LINES / 2;
    nX = COLS / 2;

    mvaddch(nY, nX, '*');

    //
    keypad(stdscr, TRUE);
    timeout(30);

    while( (ch != 'q') && (ch != 'Q') )
    {
        // 사용자 키 입력받기
        ch = getch();

        switch(ch)
        {
        case KEY_UP:
            mvaddch(nY, nX, ' ');
            nY = nY - 1;
            mvaddch(nY, nX, '*');
            break;
        case KEY_DOWN:
            mvaddch(nY, nX, ' ');
            nY = nY + 1;
            mvaddch(nY, nX, '*');
            break;
        case KEY_LEFT:
            mvaddch(nY, nX, ' ');
            nX = nX - 1;
            mvaddch(nY, nX, '*');
            break;
        case KEY_RIGHT:
            mvaddch(nY, nX, ' ');
            nX = nX + 1;
            mvaddch(nY, nX, '*');
            break;
        }
    }

    // 터미널 닫기
    endwin();
    return 0;
}