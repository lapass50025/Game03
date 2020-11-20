#include <ncursesw/curses.h>
#include <locale.h>



int main(void)
{
    int nX = 0;
    int nY = 0;

    char *str = "안녕하세요, RAPA 탈출!!! ♥";
    int ch = 0;


    setlocale(LC_ALL, "ko_KR.utf8");
    setlocale(LC_CTYPE, "ko_KR.utf8");

    // 터미널 초기화하기
    initscr();
    curs_set(0);

    nY = LINES / 2;
    nX = COLS - 1;

    //
    timeout(50);

    while( (ch != 'q') && (ch != 'Q') )
    {
        // 사용자 키 입력받기
        ch = getch();

        clrtoeol();
        mvprintw(nY, nX, str);
        nX = nX - 1;
    }

    // 터미널 닫기
    endwin();
    return 0;
}
